#include<bits/stdc++.h>
#define int long long
using namespace std;
int read();
int c,n,m,d,q,w[500010],cnt[500010],b[500010][21],t[500010][21],a[510][510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=0;j<k;j++){
			int to=read(),tt=read();
			b[to][cnt[to]]=i;
			t[to][cnt[to]]=tt;
			cnt[to]++;
		}
	}
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;i++){
		a[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<cnt[i];j++){
			for(int k=0;k<cnt[i];k++){
				a[b[i][j]][b[i][k]]=min(a[b[i][j]][b[i][k]],t[i][j]+t[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	while(q--){
		int x=read(),y=read(),ans=1e18;
		for(int i=0;i<cnt[x];i++){
			for(int j=0;j<cnt[y];j++){
				ans=min(ans,a[b[x][i]][b[y][j]]+t[x][i]+t[y][j]+w[x]+w[y]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
int read(){
	int s=0,sg=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')sg=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*sg;
}