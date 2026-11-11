#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const long long N=2e5+10;
long long n,m,ans,a[N],p[N],vis[N];
void dfs(long long id){
	if(id>m){
		long long t=p[1];
		for(long long i=2;i<=m;++i)
			t=t&p[i];
		ans=max(ans,t);
		return;
	}
	for(long long i=1;i<=n;++i)
		if(!vis[i]){
			vis[i]=1;
			p[id]=a[i];
			dfs(id+1);
			vis[i]=0;
		}
}
void dfs2(long long id){
	if(id>2){
		ans=max(ans,a[1]&a[2]);
		return;
	}
	for(long long i=1;i<=n;++i)
		if(!vis[i]){
			vis[i]=1;
			p[id]=a[i];
			dfs(id+1);
			vis[i]=0;
		}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;++i) cin>>a[i];
	if(m==1) for(long long i=1;i<=n;++i) ans=max(ans,a[i]);
	else if(m==n){
		ans=a[1];
		for(long long i=1;i<=n;++i) ans=ans&a[i];
	}
	else if(m==2) dfs2(1);
	else if(m==n-1){
		for(long long i=1;i<=n;++i){
			long long t;
			if(i==1) t=a[2];
			else t=a[1];
			for(long long j=1;j<=n;++j)
				if(i!=j) t=t&a[i];
			ans=max(ans,t);
		}
	}
	else dfs(1);
	cout<<ans;
	return 0;
}
