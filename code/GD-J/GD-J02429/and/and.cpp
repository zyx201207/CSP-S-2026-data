#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=1e18;
ll n,m,a[200010],ans=-1,maxn=-1;
string s[200010];
void dfs(ll i,ll cnt,ll sum){
	if(i>n)return;
	if(cnt==m){
		ans=max(ans,sum);
		return;
	}
	dfs(i+1,cnt,sum);
	if(sum==0){
		dfs(i+1,cnt+1,a[i]);
	}else{
		dfs(i+1,cnt+1,sum&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		/*ll tot=a[i];
		string t="";
		while(tot>0){
			t+=to_string(tot%2);
			tot/=2;
		}
		string ts="";
		for(int j=t.size()-1;j>=0;j--)
			ts+=t[j];
		s[i]=ts;*/
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i]==a[j])continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
