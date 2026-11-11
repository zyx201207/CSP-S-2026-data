#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long a[2000005];
long long check(int x,int y){
//	cout<<1<<"\n";
	long long num=0;
	long long ans=0;
	for(int j=y+1;a[j]-a[y]<=d,j<=n;j++){
//		cout<<x<<"\n";
		num=0;
		for(int i=x+1;i<j;i++){
			if(num>2){
				break;
			}
			if(a[i]-a[x]<=d && a[j]-a[i]<=d){
//				cout<<x<<" "<<i<<" "<<j<<"\n";
				num++;
			}
		}
		if(num==2){
			ans++;
		}
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>d){
					ans+=check(i,j-1);
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
