#include<bits/stdc++.h>
#define rep(i,n,m) for(int i(n);i<=(m);++i)
#define rev(i,n,m) for(int i(n);i>=(m);--i)
#define int long long
using namespace std;
const int N=2e5+5;
int pre[N],nxt[N],Left[N],Right[N],a[N];
int Case,T,n,d,L[N],R[N];
int dfs1(int u){
	if(L[u]!=-1||u<=0) return L[u];
	int itl=lower_bound(a+1,a+n+1,a[u]-d)-a;
	int itr=lower_bound(a+1,a+n+1,a[u+1]-d)-a;
//	cerr<<u<<":"<<itl<<" "<<itr<<" "<<Left[itl]<<"\n";
	L[u]=itr-itl+itl-Left[itl];
	if(Left[itl]!=u) L[u]+=dfs1(Left[itl]);
	return L[u];
}
int dfs2(int u){
	if(R[u]!=-1||u>n) return R[u];
	int itl=upper_bound(a+1,a+n+1,a[u-1]+d)-a-1;
	int itr=upper_bound(a+1,a+n+1,a[u]+d)-a-1;
//	cout<<u<<":"<<itl<<" "<<itr<<"\n";
	R[u]=itr-itl+Right[itr]-itr;
//	cout<<u<<":"<<R[u]<<"\n";
	if(Right[itr]!=u) R[u]+=dfs2(Right[itr]);
	return R[u];
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>Case>>T;
	while(T--){
		int ans=0;
		cin>>n>>d;
		rep(i,1,n) pre[i]=nxt[i]=Left[i]=Right[i]=0,L[i]=R[i]=-1;
		rep(i,1,n) cin>>a[i];
		if(a[1]+d<a[3]&&a[1]+d>=a[2]){
			pre[2]=1,nxt[1]=2;
		}
		rep(i,3,n){
			if(a[i]-a[i-2]>d&&a[i]-a[i-1]<d){
				pre[i]=i-1,nxt[i-1]=i;
			}
		}
		rep(i,1,n) Left[i]=Right[i]=i;
		rep(i,1,n){
			if(!nxt[i]){
				int j=i;
				while(j!=0){
					Right[j]=i;
					j=pre[j];
				}
			}
			if(!pre[i]){
				int j=i;
				while(j!=0){
					Left[j]=i;
					j=nxt[j];
				}
			}
		}
		rep(i,2,n-2){
			int j=i+1;
			if(i<n-1&&a[i-1]+d>=a[i+2]||a[i]+d<a[j]) continue;
			int L1=lower_bound(a+1,a+n+1,a[j+1]-d)-a;
			int L2=lower_bound(a+1,a+n+1,a[i]-d)-a;
			int R1=upper_bound(a+1,a+n+1,a[j]+d)-a-1;
			int R2=upper_bound(a+1,a+n+1,a[i-1]+d)-a-1;
			if(L1>i||R2<j) continue;
//			cerr<<i<<" "<<j<<" "<<L1<<" "<<L2<<" "<<R1<<" "<<R2<<" "<<dfs1(L2)<<" "<<dfs2(R1)<<"\n";
//			cout<<(dfs1(L2)+L1-L2)<<" "<<(dfs2(R1)+R1-R2)<<"\n";
			ans+=1ll*(dfs1(L2)+L1-L2)*(dfs2(R1)+R1-R2);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*

*/
