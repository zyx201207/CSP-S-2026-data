#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e6+8;
int c,t;
ll n,d,ans;
ll x[MAXN],sum[MAXN];
void dfs(int st,int cnt){
	if(cnt==2){
		sum[st]++;
		return;
	}		
	for(int i=st+1;i<=n;i++)
		if(abs(x[i]-x[st])<=d)
			dfs(i,cnt+1);	
}
int solve(){
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(sum[i]==2)
			cnt++;
	return cnt;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		fill(x+1,x+n+1,0);
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		if(x[n]-x[1]+1<d*2){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n-d;i++)
			dfs(i,0),ans+=solve(),fill(sum+1,sum+n+1,0);
		cout<<ans<<endl;
	}
}
/*
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
