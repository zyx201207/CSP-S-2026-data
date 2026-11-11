#include<iostream>
using namespace std;
#define ll long long
ll x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,ans=0;
		ll d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		ll d1=x[2]-x[1];
		ll rp=d/d1;
		for(int i=1;i<=n-3;i++){
			int cnt=2;
			for(int j=i+3;j<=n;j+=2){
				if(cnt*d1>d) break;
				else if((cnt+cnt-1)*d1>d){
					ans++;
				}
				cnt++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
