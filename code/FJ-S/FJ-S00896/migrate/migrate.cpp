#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],cnt,minn,ans;
void dfs(int u,int t,int stp){
	if(u==t){
		if(stp==minn) cnt++;
		if(stp<minn){
			cnt=1;
			minn=stp;
		}
		return;
	}
	for(int i=u+1;i<=t;i++){
		if(a[i]-a[u]<=d) dfs(i,t,stp+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
//			memset(f,-1,sizeof(f));
//			f[i]=0;
			for(int j=i+1;j<=n;j++){
//				int l=upper_bound(a+i,a+j,a[j]-d)-a;
//				if(a[l-1]==a[j]-d) l--;
//				l=max(l,i);
//				l=min(l,j-1);
//				f[j]=f[l]+1;
//				int r=upper_bound(f+l,f+j,f[l])-f;
//				r=min(r,j);
//				if(r-l==2) ans++;
				cnt=0;
				minn=LLONG_MAX;
				dfs(i,j,0);
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

