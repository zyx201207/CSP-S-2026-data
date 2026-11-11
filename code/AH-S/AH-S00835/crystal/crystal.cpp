#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
int a[N];int n,m,ans=0;int b[N];
int juli(int u){
	int sum=0;
	int zhenr=0;
	int sheng=m;
	int l=1,r=n,mid=(l+r)/2;
	while(1){
		mid=(l+r)/2;
		if(a[mid]>u){
			r=mid;
		}
		else{
			l=mid;
		}
		if(l+1==r) break;
	}
	for(int i=1;i<=n;i++){
		if(a[i]>u){
			zhenr=i-1;
			break;
		}
		else if(a[i]==u){
			zhenr=i;
		}
	}
	for(int i=zhenr;i>=1;i--){
		if((sheng+a[i])<u){
			break;
		} 
		sheng-=(u-a[i]);
		sum++;
	}
	return sum;
}
bool pan_A(){
	for(int i=1;i<=n;i++){
		if(a[i]!=i) return 0; 
	}
	return 1;
}
bool pan_B(){
	int cha=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if((a[i]-a[i-1])!=cha) return 0; 
	}
	return 1;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(pan_A()){
		
		for(int i=1;i<=n;i++){
			b[i]=(i*(i-1))/2;
		}
		for(int i=1;i<=n;i++){
			if(b[i]>m){
				cout<<b[i]-1;
				return 0;
			}
		}
		cout<<n;
	}
	else if(pan_B()){
		int cz=a[2]-a[1];
		for(int i=1;i<=n;i++){
			b[i]=(a[i]*((a[i]-a[1])/cz+1))-((a[1]+a[i])*((a[i]-a[1])/cz+1)/2);
		}
		for(int i=1;i<=n;i++){
			if(b[i]>m){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n<<endl;
	}
	else {
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			int y=juli(a[i]);
			ans=max(ans,y);
		}
		cout<<ans;
	}
	
	return 0;
}

