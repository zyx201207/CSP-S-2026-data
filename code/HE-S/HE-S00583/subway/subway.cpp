#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll c,n,m,d,q;
ll w[N],e[555][555];
vector<ll> a[N],t[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(e,0x3f,sizeof(e));
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		ll k;
		scanf("%lld",&k);
		e[i][i]=0;
		for(int j=1;j<=k;j++){
			ll x,y;
			scanf("%lld%lld",&x,&y);
			a[x].push_back(i);
			t[x].push_back(y);
		}
	}
	
	for(int i=1;i<=m;i++){
		ll l=a[i].size();
		for(int j=0;j<l;j++){
			for(int k=j+1;k<l;k++){
				ll v=a[i][j],u=a[i][k];
				e[v][u]=(t[i][j]+t[i][k])<e[v][u]?(t[i][j]+t[i][k]):e[v][u];
				e[u][v]=e[v][u];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=n;k++){
				e[i][j]=(e[i][k]+e[j][k])<e[i][j]?(e[i][k]+e[j][k]):e[i][j];
				e[j][i]=e[i][j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		ll ans=0x3f3f3f3f3f3f3f3f,x,y;
		scanf("%lld%lld",&x,&y);
		ll l1=a[x].size(),l2=a[y].size();
		for(int j=0;j<l1;j++){
			for(int k=0;k<l2;k++){
				ans=(t[x][j]+t[y][k]+e[a[x][j]][a[y][k]])<ans?(t[x][j]+t[y][k]+e[a[x][j]][a[y][k]]):ans;
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
