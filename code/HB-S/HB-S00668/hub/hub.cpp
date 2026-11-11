#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=305;
int C,T,n,k,a[N],book[N],c[N],maxn,minn,ans,res;
vector<int>e[N];
void dfs(int x){
	book[x]=1;
	for(int i=0;i<(signed)e[x].size();i++){
		int y=e[x][i];
		if(book[y]) continue;
		dfs(y);
	}
	return ;
}
void check(int x,int f,int cnt){
	if(c[x]){
		ans=min(ans,cnt);
		return ;
	}
	for(int i=0;i<(signed)e[x].size();i++){
		int y=e[x][i];
		if(y==f) continue;
		check(y,x,cnt+1);
	}
	return ;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%lld%lld",&x,&y);
			e[x].push_back(y);
			e[y].push_back(x);
		} 
		minn=0x3f3f3f3f3f3f3f;
		for(int i=0;i<(1<<n);i++){
			int cnt=0;
			memset(c,0,sizeof c);
			memset(a,0,sizeof a);
			for(int j=1;j<=n;j++){
				book[j]=1;
				if(i&(1<<(j-1))){
					cnt++;
					book[j]=0;
					a[cnt]=j;
					if(cnt>k) break;
				}
			}
			if(cnt!=k) continue;
			cnt=0;
			for(int j=1;j<=k;j++){
				c[a[j]]=1;
				if(!book[a[j]]){
					cnt++;
					if(cnt>2) break;
					dfs(a[j]);
				}
			} 
			if(cnt>2) continue;
			maxn=0;
			for(int j=1;j<=n;j++){
				if(c[j])continue;
				ans=0x3f3f3f3f3f3f3f;
				check(j,0,0);
				maxn=max(maxn,ans);
			} 
			minn=min(minn,maxn);
		}
		cout<<minn<<endl;
	}
	return 0;
}
