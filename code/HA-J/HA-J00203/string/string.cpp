#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
string sum;
void dfs(ll x,ll y,ll cnt){
	if(x==y||y-x==1){
		cout<<cnt;
		return;
	}if(sum[x]!=sum[y]){
		sum[x]=sum[y];
		dfs(x+1,y+1,cnt+1);
	}else dfs(x+1,y+1,cnt);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll ans=0,ansed=1;
	for(int i=1;i<=n;i++){
		ll a;
		ans+=a;
		char s;
		cin>>a>>s;
		for(int i=ansed;i<=ans;i++) sum[i]=s;
		ansed=ans;
	}dfs(1,ans,0);
	return 0;
}
