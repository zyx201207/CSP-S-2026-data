#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int C,T,n,d,ans,a[5010],f[5010],tr[5010];
inline int lowbit(int x){return x&-x;}
inline void add(int x,int v){for(int i=x;i<=n+1;i+=lowbit(i)) tr[i]+=v;}
inline int sum(int x){int res=0;for(int i=x;i>0;i-=lowbit(i)) res+=tr[i];return res;}
inline int query(int l,int r){return sum(r)-sum(l-1);}
inline void ji(int x){
	for(int i=1;i<=n+1;i++) tr[i]=0;
	for(int i=1;i<=x;i++) f[i]=0;f[x]=1;add(1,1);
	for(int i=x-1,j=x;i>=1;i--){
		while(a[j]-a[i]>d&&j>=i&&j>=1) add(f[j],-1),j--;
		if(i==j) break;
		if(query(f[j],f[j])==2) ans++;
		f[i]=f[j]+1;add(f[i],1);
	}
//	cout<<"!";for(int i=1;i<=x;i++) cout<<f[i]<<' ';cout<<'\n';
}
inline void solve(){
	cin>>n>>d;for(int i=1;i<=n;i++) cin>>a[i];
	ans=0;
	for(int i=1;i<=n;i++) ji(i);
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>C>>T;while(T--) solve();
	return 0;
}
/*
0 4
4 2
1 2 3 4
5 2
1 2 3 4 5
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
我服了，最后0.5h想出T3正解 ，没时间了，暴力还没调出来，希望不要挂分，RP++ 
*/
