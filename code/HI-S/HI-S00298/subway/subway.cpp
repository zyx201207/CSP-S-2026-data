#include<bits/stdc++.h>
#define afor(i,x,y) for(int i=(x);i<=(y);i++)
#define bfor(i,x,y) for(int i=(x);i>=(y);i--)
using namespace std;
typedef long long ll;
const int N=510,M=5e5+10;
int C,n,m,d,q,w[M];
ll f[N][N];
vector<pair<int,int>> s[M];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&C,&n,&m,&d,&q);
	afor(i,1,m) scanf("%d",&w[i]);
	afor(i,1,n) {
		int k,x,t;
		scanf("%d",&k);
		afor(j,1,k) {
			scanf("%d%d",&x,&t);
			s[x].push_back({i,t});
		}
	}
	memset(f,0x3f,sizeof f);
	afor(i,1,m) afor(j,0,s[i].size()-1) afor(k,0,j-1) {
		pair<int,int> x=s[i][j],y=s[i][k];
		f[x.first][y.first]=f[y.first][x.first]=
			min(f[x.first][y.first],(ll)x.second+y.second);
	}
	afor(i,1,n) f[i][i]=0;
	afor(k,1,n) afor(i,1,n) afor(j,1,n)
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	afor(i,1,q) {
		int x,y;
		scanf("%d%d",&x,&y);
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(pair<int,int> i:s[x]) for(pair<int,int> j:s[y])
			ans=min(ans,f[i.first][j.first]+i.second+j.second);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
