#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,w[N],k[505],val[505][505];
vector<int> st[N],ct[N];
signed main( ){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) val[i][j]=1e17;
		val[i][i]=0;
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int an,tn;
			cin>>an>>tn;
			st[an].push_back(i);
			ct[an].push_back(tn);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<st[i].size();j++){
			for(int p=j+1;p<st[i].size();p++){
				int u=st[i][j],v=st[i][p];
				val[u][v]=min(val[u][v],ct[i][j]+ct[i][p]);
				val[v][u]=val[u][v];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(val[i][j]>=1e17) continue;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++){
				val[i][j]=min(val[i][j],val[i][k]+val[k][j]);
			}

	for(int i=1;i<=q;i++){
		int str,ed,tot=1e18;
		cin>>str>>ed;
		for(int j=0;j<st[str].size();j++){
			for(int p=0;p<st[ed].size();p++){
				int u=st[str][j],v=st[ed][p];
				tot=min(tot,val[u][v]+ct[str][j]+ct[ed][p]);
			}
		}
		tot+=w[str]+w[ed];
		cout<<tot<<'\n';
	} 
	return 0;
}

