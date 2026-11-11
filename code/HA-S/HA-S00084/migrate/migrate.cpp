#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,d,T,n,a[2000005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		bool f=1;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>=3){
				if(a[i]-a[i-1]!=a[i-1]-a[i-2]) f=0;
			}
		}if(f){
			if(a[2]-a[1]>d){
				cout<<0;
			}else{
				ll ans=0;
				ll s=d/(a[2]-a[1]);
				for(int i=1;i<=n-s;i++){
					ans+=n-s-i+1;
				}
				cout<<ans<<"\n";
			}
		}else{
			cout<<0<<"\n";
		}
	}
	return 0;
}
