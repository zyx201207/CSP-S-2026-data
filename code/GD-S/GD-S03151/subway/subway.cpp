#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e3+5,MAXM=5e5+5;
ll c,n,m,d,q,w[MAXM],a[MAXN][MAXN],t[MAXN][MAXN],k[MAXN],x[MAXN],y[MAXN];
void scan(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
}
void slove(){
	for(int k=1;k<=q;k++){
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(a[k][i]%2) ans+=a[k][i];
			else ans+=t[k][i];
			if(a[i][k]%k) ans*=k;
			//ans=min(ans-a[i][k],ans-t[i][k]);
		}
		cout<<ans<<endl;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	scan();
	slove();
	return 0;
}
