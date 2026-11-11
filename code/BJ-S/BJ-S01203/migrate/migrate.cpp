#include<bits/stdc++.h>
using namespace std;
#define CO const
#define CC constexpr
#define CA CO auto
#define RE return
#define VE vector
#define PB push_back
#define FI first
#define SE second
#define TET template<class T>
using ll=long long;
using Ci=CO int;using Cl=CO ll;
#define FOR(i,l,r) for(int i=(l);i<=(r);++i)
#define FER(i,r,l) for(int i=(r);i>=(l);--i)
TET using pq=priority_queue<T,VE<T>,greater<>>;
TET CC void Max(T&x,T y){x=max(x,y);}
TET CC void Min(T&x,T y){x=min(x,y);}
CC int N=2e6+5;
int zq,T;
int n;
ll m,a[N];
int p[N];
int f[N][2],g[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>zq>>T;
	while(T--){
		cin>>n>>m;
		FOR(i,1,n){
			cin>>a[i];
			f[i][0]=f[i][1]=g[i]=0;
		}
		p[n]=n;
		FER(i,n-1,1){
			p[i]=p[i+1];
			while(a[p[i]]-a[i]>m)--p[i];
		}
		ll an=0;
		FOR(i,1,n){
			Ci j=p[i];
			if(i>2){
				an+=f[i][0]*max(0,min(j-1,p[i-1])-max(i,p[i-2]));
				an+=g[i];
			}
			if(j==i)continue;
			++f[j][0];
			if(p[i-1]<j){
				f[j][p[i-1]==j-1]+=f[i][0]+f[i][1];
				g[j]+=g[i];
				an+=(ll)g[i]*(j-p[i-1]-1);
			}else if(p[i-2]!=j)g[j]+=f[i][0];
		}
		cout<<an<<'\n';
	}
	RE 0;
}