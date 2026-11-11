//GZ-S00028 遵义市第四初级中学 廖奕德
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int c,n,m,d,q,w[500001],k[501],a[501][1001],t[501][1001],x,y,s[500001],ds[500001],f[500001],i,j;
vector<pair<int,int> > b[500001];
void cc(int x) {
	if(ds[x]>=d+1)
		return;
	for(int i=0; i<b[x].size(); i++)
		if(f[b[x][i].first])
			s[b[x][i].first]=min(s[b[x][i].first],b[x][i].second+s[x]),ds[b[x][i].first]++,f[b[x][i].first]=0,cc(b[x][i].first);
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(i=1; i<=m; i++)
		cin>>w[i];
	for(i=1; i<=n; i++) {
		cin>>k[i];
		for(j=1; j<=k[i]; j++)
			cin>>a[i][j]>>t[i][j];
	}
	for(i=1; i<=n; i++)
		if(k[i]==2)
			b[a[i][1]].push_back({a[i][2],t[i][1]+t[i][2]}),b[a[i][2]].push_back({a[i][1],t[i][1]+t[i][2]});
	if(7<=c&&c<=11||c==0)
		for(i=1; i<=q; i++) {
			for(j=1; j<=n; j++)
				s[j]=1e9,ds[j]=0,f[j]=1;
			cin>>x>>y;
			s[x]=0;
			cc(x);
			cout <<s[y]+w[x]+w[y]<<endl;
		}
}

