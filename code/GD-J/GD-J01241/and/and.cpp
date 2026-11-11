#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010],mans=0;
bool b[200010];
void dfs(int now,int cnt){
	if((now==n+1||cnt==m+1)){
		if(cnt<m) return ;
		int ans=-1;
		for(int i=1;i<=n;i++){
			if(ans==-1&&b[i])ans=a[i];
			else if(b[i])ans&=a[i]; 
		}
		mans=max(mans,ans);
		return ;
	}
	b[now]=true;
	dfs(now+1,cnt+1);
	b[now]=false;
	dfs(now+1,cnt);
}
signed main(){
	freopen("and2.in","r",stdin);
	freopen("and2.out","w",stdout);
	cin>>n>>m;
	int mx=0,lg2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		float t=log2(a[i]+1);
		if(t==signed(t))lg2++;
	}
	if(m==1){
		cout<<mx;
	}
	else if(n==m){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	else{
		dfs(1,0);
		cout<<mans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
