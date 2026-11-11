#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||'9'<c){
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=301;
ll c,t,n,d,x[N],dp[N][N],cnt[N][N],ans;
deque<int> q;
void solve(){
	n=read();d=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=1e18;
			cnt[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		x[i]=read();dp[i][i]=0;
	}
	for(int s=1;s<=n;s++){
		for(int i=s+1;i<=n;i++){
			for(int j=s;j<i;j++){
				if(x[i]-x[j]<=d){
					ll tmp=dp[s][j]+1;
					if(tmp<dp[s][i]){
						dp[s][i]=tmp;
						cnt[s][i]=cnt[s][j];
					}else if(tmp==dp[s][i]){
						cnt[s][i]+=cnt[s][j];
					}
				}
			}
		}
	}
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==2) ans++;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	while(t--){
		solve();
	}
}
