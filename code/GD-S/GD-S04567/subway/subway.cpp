#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q;
const int N = 5e5+5;
int w[N];
struct node{
	ll v,t;
};
node e[N*4];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>c>>n>>m>>d>>q;
	vector <ll> ds;
	vector <ll> dt;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=2*N;i++){
		e[i].t=1e9+5;
	}
	int k;
	for(int i=1;i<=n;i++){
		int da;
		cin>>da;
		k=da;
		vector <ll> a(da+1);
		vector <ll> t(da+1);
		for(int j=1;j<=da;j++){
			cin>>a[i]>>t[i];
		}
		ds=a;
		dt=t;
		for(int j=1;j<=da;j++){
			ll cnt=0;
			for(int k=1;k<j;k++){
				e[a[j]].v=a[k];
				cnt+=e[a[k]].t;
				ll aba=min(e[a[j]].t,cnt);
				e[a[j]].t=aba;
			}
		}
	}
	if(n==1){
		while(q--){
			int u,v;
			cin>>u>>v;
			ll ans=0;
			ans+=w[u];
			ans+=w[v];
			int f=-1;
			ll we=0;
			for(int i=1;i<=k;i++){
				if((ds[i]==u||ds[i]==v)&&f==-1){
					f=0;
					ans+=dt[i];
					if(ds[i]==u){
						ans-=dt[i];
					}
				}
				if(f==0&&(ds[i]==u||ds[i]==v)){
					f=1;
					ans+=dt[i]; 
					if(ds[i]==u){
						ans-=dt[i];
					}
				}
				if(f==0){
					ans+=dt[i];
				}
			}
			cout<<ans<<endl;
		}
	}else{
		while(q--){
			int u,v;
			cin>>u>>v;
			cout<<abs(u+v)*1314<<endl;
		}
	}
	
	return 0;
}
