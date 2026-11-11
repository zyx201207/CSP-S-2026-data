#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005],n,m;
ll ans=0;
void dfs(ll t,ll sum,ll cnt){
	if(t>n){
		if(cnt==m)ans=max(ans,sum);
		return;
	}
	dfs(t+1,sum&a[t],cnt+1);
	dfs(t+1,sum,cnt);
}
bool checkA(){
	for(int i=1;i<=n;i++){
		if((a[i]&(a[i]+1))!=0)return 0;
	}
	return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=20){
		dfs(1,(1ll<<31)-1,0);
		cout<<ans;
	}
	else if(n==m){
		for(int i=1;i<=n;i++)
			ans=(ans&a[i]);
		cout<<ans;
	}
	else if(m==1){
		for(int i=1;i<=n;i++)
			ans=max(a[i],ans);
		cout<<ans;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)ans=max(ans,a[i]&a[j]);
		}
		cout<<ans;
	}
	else if(checkA()){
		sort(a+1,a+n+1);
		cout<<a[k];
	}
	else{
		dfs(1,(1ll<<31)-1,0);
		cout<<ans;
	}
	return 0;
}
