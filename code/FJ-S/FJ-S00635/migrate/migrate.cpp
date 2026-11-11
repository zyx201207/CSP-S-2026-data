#include<bits/stdc++.h>
using namespace std;
int Cx,Tx;
int a[2000005];
int n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>Cx>>Tx;
	if(Cx==11||Cx==12){
		while(Tx--){
			long long ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			if(a[2]-a[1]>d){
				cout<<0;
				return 0;
			}
			int flag1,flag2;
			for(int i=2;i<=n;i++){
				if(a[i]-a[1]>d){
					flag1=i;
					break;
				}
			}
			for(int i=2;i<=n;i++){
				if(a[i]-a[1]>d*2){
					flag2=i-1;
					break;
				}
			}
			for(int i=1;i<=n-flag1+1;i++){
				if(i+flag2<=n+1){
					ans+=flag2-flag1+1;
				}
				else{
					ans+=n-flag1+1;
				}
			}
			cout<<ans<<'\n'; 
		}
	}
	return 0;
}
