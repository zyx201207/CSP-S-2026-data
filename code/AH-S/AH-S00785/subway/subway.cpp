#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long js[1005],c,n,m,d,q,w[1005],k[1005],a[105][105],t[105][105],tt,p[1001][1005],x,y,ans;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(js,0,sizeof(js));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];tt=t[i][j];p[a[i][j]][js[a[i][j]]]=i;
			js[a[i][j]]++;
		}
	}
	while(q--){
		cin>>x>>y;
		for(int i=1;i<=js[x];i++){
			for(int j=1;j<=js[y];j++){
				if(p[x][i]==p[y][j])ans=tt*2+w[x]+w[y];
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
