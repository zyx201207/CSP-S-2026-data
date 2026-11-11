#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define mm 500005
#define mn 505
using namespace std;
long long w[mm],f[mn][mn],t[mm][21],ans;
int c,n,m,d,q,a[mm][21],fa,ft,k,sz[mm],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>fa>>ft;
			sz[fa]++;
			a[fa][sz[fa]]=i;
			t[fa][sz[fa]]=ft;
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
		if(i!=j) f[i][j]=1000000000000000000ll;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=sz[i];j++)
		for(int o=j+1;o<=sz[i];o++)
		f[a[i][o]][a[i][j]]=f[a[i][j]][a[i][o]]=min(f[a[i][j]][a[i][o]],t[i][j]+t[i][o]);
	}
	for(int o=1;o<=n;o++)
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	f[j][i]=f[i][j]=min(f[i][j],f[i][o]+f[o][j]);
	for(int rp=1;rp<=q;rp++){
		cin>>x>>y;
		ans=1000000000000000000ll;
		for(int i=1;i<=sz[x];i++)
		for(int j=1;j<=sz[y];j++)
		ans=min(ans,f[a[x][i]][a[y][j]]+t[x][i]+t[y][j]);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
