#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define il inline
#define fr(i,a,b) for(int i=a;i<=b;++i)
#define Fr(i,a,b) for(int i=a;i>=b;--i)
il int rd(){
	int x=0,f=1; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	return x*f;
}
const int N=5e5+5;
const ll inf=1e18;
int c,d,n,m,q,w[N];
ll f[520][520];
struct l{int v,w;};
vector<l> e[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=rd(),n=rd(),m=rd(),d=rd(),q=rd();
	fr(i,1,m) w[i]=rd();
	fr(i,1,n) fr(j,1,n){
		if(i!=j) f[i][j]=inf;
	}
	fr(i,1,n){
		int k=rd(),x,y;
		fr(j,1,k){
			x=rd(),y=rd();
			e[x].push_back({i,y});
		}
	} fr(i,1,m){
		int a=e[i].size()-1;
		fr(j,0,a) fr(t,0,a){
			if(j==t) continue;
			f[e[i][j].v][e[i][t].v]=e[i][j].w+e[i][t].w;
			f[e[i][t].v][e[i][j].v]=e[i][j].w+e[i][t].w;
		}
	} fr(k,1,n){
		fr(i,1,n){
			fr(j,1,n){
				if(f[i][k]==inf||f[k][j]==inf) continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x=rd(),y=rd();
		ll ans=inf;
		int lx=e[x].size()-1,ly=e[y].size()-1;
		fr(i,0,lx){
			fr(j,0,ly){
				l a=e[x][i],b=e[y][j];
				ans=min(ans,f[a.v][b.v]+a.w+b.w);
			}
		} cout<<ans+w[x]+w[y]<<endl;
	}
    return 0;
}
