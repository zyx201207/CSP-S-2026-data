#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005],g[505][505],dist[505],vis[505],s[505];
long long a[505],t[505],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(g,0x3f,sizeof(g));
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	} 
	long long orb1=1e9+5,orb2=1e9+5;
	for(long long i=1;i<=n;i++){
		cin>>s[i];
		for(long long j=1;j<=s[i];j++){
			cin>>a[j]>>t[j];
		}
	}
	for(long long i=1;i<=q;i++){
		long long x,y;
		cin>>x>>y;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=s[i];j++){
				if(a[j]==x)orb1=min(orb1,t[j]);
				if(a[j]==y)orb2=min(orb2,t[j]);
			}
		}
		cout<<w[x]+w[y]<<endl;
	}
	return 0;
}
