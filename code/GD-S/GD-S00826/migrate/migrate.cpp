#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,T,n,d,a[1000010],f[1000010];
vector<ll> b[10010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		ll ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		ll l=1;
		b[1].push_back(1LL);
		for(int i=1;i<=n;i++){
			for(int j=i+1; ;j++){
//				cout<<"yes";
				if(a[j]<=a[i]+d) break;
				ll t1=j;
//				ll t1;
				if(b[i].size()!=0){
					for(ll k=0;k<b[i].size();k++){
						ll t=b[i*1LL][k*1LL]+1;
						b[j*1LL].push_back(t);
					}
//					cout<<"yes";
				}
				else{
					b[j].push_back(1);
				}
//				b[t1].push_back(2);
			}
		}
		for(int i=2;i<=n;i++){
			int v[100010];
			int t=b[i].size();
			for(int j=0;j<t;j++){
				v[b[i][j]]++;
				if(v[b[i][j]]==2){
					ans++;
				}
				if(v[b[i][j]]==3){
					ans--;
				}
			}
		}
//		cout<<"\n";
		cout<<ans<<endl;
	}
} 
