#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(j);i<=(k);++i)
#define dwn(i,j,k) for(int i=(j);i>=(k);--i)
using namespace std;
#define int long long
const int N=2e6+7;
int a[N],n,d,lst[N],nxt[N],sump[N],sums[N],f[N],mn[N];
void solve(){
	cin>>n>>d;
	rep(i,1,n)cin>>a[i],lst[i]=nxt[i]=sump[i]=sums[i]=0;
	sums[0]=sump[0]=sums[n+1]=sump[n+1]=0;
	nxt[n+1]=n;
	dwn(i,n,1){
		int tmp=nxt[i+1];
		while(a[tmp]-a[i]>d)--tmp;
		nxt[i]=tmp;
	}lst[0]=1;
	rep(i,1,n){
		int tmp=lst[i-1];
		while(a[i]-a[tmp]>d)++tmp;
		lst[i]=tmp;
	}
	sums[n]=0;sump[1]=0;
	dwn(i,n,2){
		if(nxt[i]-nxt[i-1]==0)continue;
		sums[i]=sums[nxt[i]]+(nxt[i]-nxt[i-1]);
	}rep(i,1,n-1){
		if(lst[i+1]-lst[i]==0)continue;
		sump[i]=sump[lst[i]]+(lst[i+1]-lst[i]);
	}int ans=0;
	rep(i,3,n-1){
		int l=1,r=1;
		l=nxt[i-1];
		r=lst[i];
		if(l>i&&r<i-1&&lst[l]==i-1&&nxt[r]==i){
			int fi=sums[i-1],se=sump[i];
			if((a[l+1]-a[i]<=d&&l<n))fi=1;
			if((r>0&&a[i-1]-a[r-1]<=d))se=1;
			ans+=fi*se;
		}
	}
	cout<<ans<<'\n';
}
void solve1(){
	cin>>n>>d;
	rep(i,1,n)cin>>a[i],lst[i]=nxt[i]=sump[i]=sums[i]=0;
	sums[0]=sump[0]=sums[n+1]=sump[n+1]=0;
	nxt[n+1]=n;
	dwn(i,n,1){
		int tmp=nxt[i+1];
		while(a[tmp]-a[i]>d)--tmp;
		nxt[i]=tmp;
	}lst[0]=1;
	rep(i,1,n){
		int tmp=lst[i-1];
		while(a[i]-a[tmp]>d)++tmp;
		lst[i]=tmp;
	}int ans=0;
	rep(i,1,n){
		queue<int>q;
		rep(j,i,n)f[j]=0,mn[j]=10000000000000ll;
		q.emplace(i);mn[i]=0;
		while(q.size()){
			int u=q.front();q.pop();
			rep(j,u+1,nxt[u]){
				if(mn[j]>mn[u]+1)mn[j]=mn[u]+1,f[j]=1,q.emplace(j);
				else if(mn[j]==mn[u]+1)++f[j],q.emplace(j);
			}
		}rep(j,i,n)if(f[j]==2)++ans;
	}cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,T;cin>>c>>T;
	if(c<=10){
		while(T--)solve1();
		return 0;
	}
	while(T--)solve();
	return 0;
}
