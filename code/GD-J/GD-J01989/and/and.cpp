#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,INF=2147483647,ANS=20000005;
ll n,m,dp[N],a[N],pre[N]={INF},ans=0;
void dfs(ll sum,ll cnt,ll now){
	if(cnt>m+1||now>n+1)return;
	if(sum>ans&&cnt==m&&sum<ANS)ans=sum;
	now++;
	dfs(sum,cnt,now);//²»Ñ¡ 
	dfs(sum=sum&a[now-1],cnt+1,now);//Ñ¡Ôñ
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	if(n<=20){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(INF,0,0);
		cout<<ans;
		return 0;
	}else if(n<=2000){
		if(m==1){
			for(int i=1;i<=n;i++){
				cin>>a[i];
				if(ans<a[i])ans=a[i];
			}
			cout<<ans;
			return 0;
		}
		else if(m==n){
			ans=INF;
			for(int i=1;i<=n;i++){
				cin>>a[i];
				ans=ans&a[i];
			}
			cout<<ans;
			return 0;
		}else{
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[i]&a[j]>ans) ans=a[i]&a[j];
				}
			}
			cout<<ans;
			return 0;
		}
	}else{
		cout<<0;
		return 0;
	}
	return 0;
}

