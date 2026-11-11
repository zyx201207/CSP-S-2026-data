#include<bits/stdc++.h>
using namespace std;
namespace MYQ{
	const int N=500005;
	int n,m,q,ww[N];
	long long a[505][505];
	basic_string<pair<int,int> >b[N];
	char buf[100005],*p1=buf,*p2=buf;
	inline char gc(){
		return (p1==p2&&(p2=(p1=buf)+fread(buf,1,100005,stdin),p1==p2))?EOF:*p1++;
	}
	inline int read(){
		int x=0;
		char y=gc();
		while(y<'0'||y>'9')
			y=gc();
		while('0'<=y&&y<='9'){
			x=(x<<3)+(x<<1)+(y^48);
			y=gc();
		}
		return x;
	}
	int main(){
		read();
		n=read(),m=read();
		read(),q=read();
		for(int i=1;i<=m;i++)
			ww[i]=read();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				a[i][j]=1e18;
			a[i][i]=0;
		}
		for(int i=1;i<=n;i++){
			int k=read(),x,y;
			while(k--){
				x=read(),y=read();
				for(int j=0;j<b[x].size();j++)
					a[b[x][j].first][i]=a[i][b[x][j].first]=min(a[b[x][j].first][i],0ll+y+b[x][j].second);
				b[x].push_back(make_pair(i,y));
			}
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
		while(q--){
			int x=read(),y=read();
			long long ans=1e18;
			for(int i=0;i<b[x].size();i++)
				for(int j=0;j<b[y].size();j++)
					ans=min(ans,a[b[x][i].first][b[y][j].first]+b[x][i].second+b[y][j].second);
			printf("%lld\n",ans+ww[x]+ww[y]);
		}
		return 0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	MYQ::main();
	return 0;
}
