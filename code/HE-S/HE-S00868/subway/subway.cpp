#include<bits/stdc++.h>
using namespace std;
const int N=500000;
long long c,n,m,wm[500001],d,q,e[501][501];
vector<long long> a[500001],t[500001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>wm[i];
	for (int i=1;i<=n;i++){
		int k;
		cin>>k;
		for (int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[x].push_back(i);
			t[x].push_back(y);
		}
	}
	for (int k=1;k<=m;k++)
		for (int i=0;i<a[m].size();i++)
		    for (int j=0;j<a[m].size();j++)
		        if (i!=j) e[a[m][i]][a[m][j]]=e[a[m][j]][a[m][i]]=t[m][i]+t[m][j];
	for (int k=1;k<=m;k++)
	    for (int i=1;i<=m;i++)
	        for (int j=1;j<=m;j++)
	            if (e[i][k]!=0 && e[k][j]!=0)
	                if (e[i][j]==0) e[i][j]=e[i][k]+e[k][j];
	                else e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
	
	for (int CQ=1;CQ<=q;CQ++){
		long long frof,tot;
	    long long ans=(5e11);
		cin>>frof>>tot;
		for (long long i=0;i<a[frof].size();i++)
		    for (long long j=0;j<a[tot].size();j++)
		        ans=min(ans,t[frof][a[frof][i]]+t[tot][a[tot][j]]+e[a[frof][i]][a[tot][j]]);
		cout<<ans<<'/n';
	}
	return 0;
}
