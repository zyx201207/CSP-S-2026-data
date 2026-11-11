#include<bits/stdc++.h>
using namespace std;
long long n,mx,ans[500005],m,a[500005],d[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	if((a[n]-a[1])*(n-1)<=m){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	d[1]=0;
	for(int i=1;i<=n;i++){
		int check=m;
		ans[i]=1;
		for(int j=i;j<=n;j++){
			if(j==i){
				if(d[j+1]<=check){
					check-=d[j+1];
//					cout<<"1+"<<i<<" "<<j<<" "<<d[j+1]<<" "<<check<<endl;
					continue;
				}
				else{
					check-=(j-i)*d[j+1];
//					cout<<i<<" "<<j<<" "<<d[j+1]<<" "<<check<<"no power"<<endl;
					ans[i]=j-i+1;
					break;
				}
			}
			if(a[j]==a[j+1]){
				ans[i]++;
//				cout<<"same"<<ans[i]<<endl;
				continue;
			}
			if(j==n){
//				cout<<"touch end"<<endl;ans[i]=j-i+1;break;
			}
			if(check==0){
//				cout<<"power if off"<<endl;ans[i]=j-i+1;break;
			}
			if((j-i+1)*d[j+1]<=check){
				if(j!=i)check-=(j-i+1)*d[j+1];
//				cout<<"+"<<i<<" "<<j<<" "<<d[j+1]<<" "<<check<<endl;
				ans[i]++;
			}
			else {
				check-=(j-i+1)*d[j+1];
//				cout<<i<<" "<<j<<" "<<d[j+1]<<" "<<check<<"check out"<<endl;
				ans[i]=j-i+1;
				break;
			}
		}
		mx=max(mx,ans[i]);
	}
	cout<<mx;
	return 0;
} 
