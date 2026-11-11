#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define gc getchar
#define pb emplace_back
inline ll re(){
	ll x=0,f=1; char c=gc();
	for(;!isdigit(c);c=gc())if(c=='-')f=-1;
	for(; isdigit(c);c=gc())x=x*10+(c-48);
	return x*f;
}
constexpr int N = 2e6+3,NN = 5e3+3;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;

namespace solve{
	int n,f[NN][NN],g[NN][NN];
	ll d,a[N],ans;
	
	void sol(){
		n=re(); d=re(); ans=0;
		for(int i=1;i<=n;i++)a[i]=re();
		if(n<4){puts("0");return;}
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)g[i][j]=0,f[i][j]=1e9;
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++)if(a[i]-a[j]<=d)f[i][j]=f[j][i]=1,g[i][j]=g[j][i]=1;
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++){
					if(f[i][k]+f[k][j]==f[i][j])
						g[i][j]+=g[i][k]*g[k][j];
					if(f[i][k]+f[k][j]<f[i][j])
						f[i][j]=f[i][k]+f[k][j],
						g[i][j]=min(3,g[i][k])*min(3,g[k][j]);
				}
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++)if(g[i][j]==2)cerr<<j<<' '<<i<<'\n',ans++;
		cout<<ans<<'\n';
	}
}//O(n^3)

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int ID=re(),T=re();
	while(T--)solve::sol();
}

