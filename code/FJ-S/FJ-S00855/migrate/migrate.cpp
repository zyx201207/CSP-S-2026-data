#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=2e6+5;
const ll INF=2e18+5;
ll n,d,x[N];

ll f[5005][5005],g[5005][5005];

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;++i){
		cin>>x[i];
	}

	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(x[j]-x[i]>d){
				f[i][j]=0;
				g[i][j]=INF;
			}else{
				f[i][j]=1;
				g[i][j]=1;
			}
		}
	}

	for(int l=3;l<=n;++l){
		for(int i=1,j=l;j<=n;++i,++j){
			for(int k=i+1;k<j;++k){
//				if(f[i][k]==0||f[k][j]==0) continue;
				if(g[i][j]>g[i][k]+g[k][j]){
					f[i][j]=f[i][k]*f[k][j];
					if(f[i][j]>3) f[i][j]=3;
					g[i][j]=g[i][k]+g[k][j];
				}else if(g[i][j]==g[i][k]+g[k][j]){
					if(f[i][j]<3){
						f[i][j]+=f[i][k]*f[k][j];
						if(f[i][j]>3) f[i][j]=3;
					}
				}
			}
		}
	}

	ll ans=0;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(f[i][j]==2){
				++ans;
			}
		}
	}
	cout<<ans<<'\n';
}

void solveA(){
	cin>>n>>d;
	for(int i=1;i<=n;++i){
		cin>>x[i];
	}
	ll k=x[2]-x[1],p=d/k;
	if(d<=k) cout<<"0\n";
	else cout<<max(n-(p+p-1),0ll)<<'\n';
}

void solveB(){
	cin>>n>>d;
	for(int i=1;i<=n;++i){
		cin>>x[i];
	}

	ll ans=0;

	for(int i=1;i<=n;++i){
		if(x[i]+d>x[n]) break;
		int p1=lower_bound(x+1,x+n+1,x[i]+d)-x;
		int p2=p1-1;
		if(p2==i) continue;
		if(x[p2]+d>x[n]) break;
		int p3=lower_bound(x+1,x+n+1,x[p2]+d)-x;
		++ans;
	}

	cout<<ans<<'\n';
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int c,t;cin>>c>>t;

	if(c==11||c==12){
		while(t--) solveA();
	}else if(c==13||c==14){
		while(t--) solveB();
	}else{
		while(t--) solve();
	}

	return 0;
}