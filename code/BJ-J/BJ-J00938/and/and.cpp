#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],mxx=-1,po,ans=-1;
char c;
void dfs(int x,long long sum,int cnt){
	if(cnt==m){
		ans=max(ans,sum);
		return ;
	}
	for(int i=x+1;i<=n-m+cnt+1;i++){
		if(sum==-1) dfs(i,a[i],cnt+1);
		else dfs(i,sum&a[i],cnt+1);
	}
}
//现在是星期六上午！
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	po=a[1];
	for(int i=2;i<=n;i++){cin>>a[i]; mxx=max(mxx,a[i]); po&=a[i];}
	if(m==1){cout<<mxx; return 0;}
	if(m==n){cout<<po; return 0;}
	dfs(0,-1,0);
	cout<<ans;
	return 0;
}