#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ep emplace
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define mems(arr,x) memset(arr,x,sizeof(arr))
#define memc(arr1,arr2) memcpy(arr1,arr2,sizeof(arr2))
#define fll(arr,x,siz) fill(arr,arr+siz+1,x)
#define cpy(arr1,arr2,siz) copy(arr2,arr2+siz+1,arr1)
using namespace std;
bool mem1;
namespace OIMATT{
	const int maxn=2e6+10;
	int n;ll d;
	ll a[maxn],f[maxn],jp[21][maxn];
	int ls[maxn],rs[maxn],son[maxn];
	int num[maxn];
	ll ans;
	// inline void trans(int u){
	// 	if(rs[u]){
	// 		if(son[rs[u]]>1)	f[u][0][0]=f[rs[u]][0][0],f[u][0][1]=f[rs[u]];
	// 		else	f[u][0][0]=f[ls[u]][1][son[rs[u]]]+f[rs[u]][0][0];
	// 	}
	// 	else	f[u][0][0]=f[ls[u]][0][0];
	// 	// f[u][0]=f[ls[u]][1]+f[rs[u]][0];
	// 	f[u][1]=son[u]+f[rs[u]][1];
	// }
	ll dfs(int u,int d,bool o){
		// printf("%d %d\n",u,o);
		num[d]++;
		if(o&&num[d]>1)return 0;
		if(num[d]>2)return 0;
		ll res=0;
		if(o&&num[d]==1)	res+=son[u];
		if(!o&&num[d]==2)	res+=son[u],o=true;
		if(rs[u])res+=dfs(rs[u],d+1,o);
		if(ls[u])res+=dfs(ls[u],d+1,o);
		return res;
		// f[u][0]=f[ls[u]][1]+f[rs[u]][0];
		// f[u][1]=son[u]+f[rs[u]][1];
		// if(!o){
		// 	if(ls[u])dfs(ls[u],1);
		// 	if(rs[u])dfs(rs[u],0);
		// 	f[u]=f[ls[u]]+f[rs[u]];
		// }
		// else{
		// 	if(rs[u])dfs(rs[u],1);
		// 	f[u]=son[u]+f[rs[u]];
		// }
	}
	void solve(int _c){
		ans=0;fll(ls,0,n);fll(rs,0,n);fll(son,0,n);fll(f,0,n);
		cin>>n>>d;
		for(int i=1;i<=n;i++)	cin>>a[i];
		// if(n>1000)return cout<<'\n',void();
		for(int i=1,j=1;i<=n;i++){
			while(j<=n&&a[j]<a[i]-d)j++;
			if(j<i&&i>1)son[i-1]-=i-j-1;
			son[i]=i-j;
			// printf("son = %d %d\n",son[i-1],son[i]);
			if(j>=i)	continue;
			if(j+1==i)rs[i]=j,ans+=(f[i]=f[j]);
			else{
				ls[i]=j+1,rs[i]=j;
				if(ls[i-1]==j||ls[i-1]==j+1)	ls[i-1]=0;
				if(rs[i-1]==j||rs[i-1]==j+1)	rs[i-1]=0;
				// trans(i-1);
				if(ls[i]==rs[i]&&ls[i-1]==rs[i-1]){
					ls[i-1]=rs[i-1]=0;
					f[i]=f[i-1];f[i-1]=0;
				}
				else if(rs[i]==ls[i-1]){
					ls[i-1]=0;
					f[i-1]=f[rs[i-1]];
					f[i]=dfs(i,0,0);
				}
				else	f[i]=dfs(i,0,0);
				ans+=f[i];
				// printf("f[%d] = %d\n",i,f[i]);
			}
			// trans(i);
			for(int j=0;num[j];j++)num[j]=0;
			// ans+=f[i][0];
			// printf("i = %d\n",i);
			// for(int j=1;j<=i;j++) printf("%d %d %d\n",j,ls[j],rs[j]);
			// printf("res = %d\n",f[i][0]);
		}
		cout<<ans<<'\n';
	}
}
bool mem2;
int main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	debug("%.2fMB\n",abs(&mem1-&mem2)/1024./1024);
	int C,T=1;cin>>C>>T;for(int i=1;i<=T;i++)OIMATT::solve(i);
	debug("%.0fms\n",double(clock())/CLOCKS_PER_SEC*1000);
}
// 28 49 63
// 28 42 63
// 7 28 49 63
// 7 28 42 63
// 7 21 42 63