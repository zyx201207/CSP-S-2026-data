#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans,pre[N],sub[N];
bool vis[N];
bool aaa(int x){
	while(x){
		if((x&1)){
			if(x!=1) return 0;
		}
		x>>=1;
	}
	return 1;
}
bool checka(){
	for(int i=1;i<=n;i++){
		int x=a[i]+1;
		if(!aaa(x)) return 0;
	}
	return 1;
}
bool checkb(){
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1) return 0;
	}
	return 1;
}
void dfs(int cur,int ss){
	if(cur>m){
		ans=max(ans,ss);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		dfs(cur+1,ss&a[i]);
		vis[i]=0;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
	}
	else if(m==n-1){
		pre[1]=a[1],sub[n]=a[n];
		pre[0]=sub[n+1]=1e18;
		for(int i=2;i<=n;i++) pre[i]=pre[i-1]&a[i];
		for(int i=n-1;i>0;i--) sub[i]=sub[i+1]&a[i];
		for(int i=1;i<=n;i++) ans=max(pre[i-1],sub[i+1]);
	}
	else if(checka()){
		sort(a+1,a+n+1);
		reverse(a+1,a+n+1);
		ans=a[1];
		for(int i=2;i<=m;i++) ans&=a[i];
	}
	else if(aaa(n)&&checkb()){
		int cnt=0;
		for(int i=n,j=m;i>=1&&j>=1;i>>=1,j--){
			if(i==1||j==1) cnt=a[i];
		}
		for(int i=0;(1<<i)<=n;i++){
			int j=1<<i,j1=1<<i+1;
			if(j1>n) break;
			if(j1-j>=m){
				int t=a[j1-1];
				for(int k=j1-2,s=m-1;s>=1;s--,k--) t&=a[k];
				ans=max(ans,t);
			}
		}
		ans=max(ans,cnt);
	}
	else if(n<=20){
		for(int i=1;i<=n;i++){
			dfs(1,a[i]);
		}
	}
	cout<<ans;
	return 0;
}
