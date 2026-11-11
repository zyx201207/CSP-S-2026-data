#include<bits/stdc++.h>
//#define F(i,a,b) for(register ll i=a;i<=b;i=-~i)
#define F(i,a,b) for(ll i=a;i<=b;i++)
#define ll long long
using namespace std;const ll N=2e6+67;
ll c,T,n,d,sum[N],mina,x[N],ans;
void dfs(ll now,ll end,ll cnt){
	if(now==end){
		sum[cnt]++;
		if(cnt<mina&&mina!=INT_MAX)sum[mina]=0;
		mina=min(mina,cnt);
		return;
	}F(i,now+1,end){
		if(x[i]-x[now]>d)break;
		dfs(i,end,cnt+1);
	}return;
}int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;ans=0;
		F(i,1,n)cin>>x[i];
		F(i,1,n-1){
			F(j,i+2,n){
				mina=LLONG_MAX;
				dfs(i,j,1);
				if(mina!=INT_MAX&&sum[mina]==2)ans++;
				if(mina!=INT_MAX)sum[mina]=0;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
