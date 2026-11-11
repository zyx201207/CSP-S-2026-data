#include<bits/stdc++.h>
#define LL long long
#define P(i,s,t) for(int i=s;i<=t;++i)
#define S(i,s,t) for(int i=s;i>=t;--i)
using namespace std;
const int N=2e6+5;
int n,l,rr;
LL m,a[N],ans,f[N],b[N],c[N];
void solve(){
	cin>>n>>m,ans=0;
	P(i,1,n) cin>>a[i];
	P(i,1,n){
		l=i,b[i]=0,f[i]=1,c[0]=1;
		P(r,i+1,n){
			f[r]=0;
			while(a[r]-a[l]>m) c[b[l]]-=f[l],++l;
			if(l==r) break;
			b[r]=b[l]+1,c[b[r]]+=f[r]=c[b[l]];
			if(f[r]==2) ans++;
			rr=r-i+1;
		}
		P(j,0,rr) c[j]=0;
	}
	cout<<ans<<'\n';
	
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int C,T;
	cin>>C>>T;
	while(T--) solve();
	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
