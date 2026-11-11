#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
vector<int> a[500],t[500];
vector<int> to[500005],tr[500005];
int w[500005];
int e[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		a[i].resize(k+1),t[i].resize(k+1);
		for(int j=1;j<=k;j++) cin>>a[i][j]>>t[i][j],to[a[i][j]].push_back(i),tr[a[i][j]].push_back(t[i][j]);
	}
	memset(e,0x3f,sizeof(e));
	for(int i=1;i<=m;i++)
		for(int j=0;j<to[i].size();j++)
			for(int k=0;k<to[i].size();k++)
				e[to[i][j]][to[i][k]]=min(e[to[i][j]][to[i][k]],tr[i][j]+tr[i][k]);
	for(int i=1;i<=n;i++) e[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			if(i!=k) for(int j=1;j<=n;j++)
				if(i!=j&&j!=k)
					e[i][j]=min(e[i][j],e[i][k]+e[j][k]);
	for(int i=1;i<=q;i++){
		int s,t,res=0x7fffffffffffffff; cin>>s>>t;
		for(int j=0;j<to[s].size();j++)
			for(int k=0;k<to[t].size();k++)
				res=min(res,tr[s][j]+tr[t][k]+e[to[s][j]][to[t][k]]);
		res+=w[s]+w[t];
		cout<<res<<'\n';
	}
	return 0;
}

