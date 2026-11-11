#include<bits/stdc++.h>
#define in long long
using namespace std;
const int N=2e5+50;
int n,m,ans,a[N];
void dfs(int x,int c,int cnt){
	if(c==m){
		ans=max(ans,cnt);
		return ;
	}
	if(x>n){
		return;
	}
	dfs(x+1,c,cnt);
	if(cnt==-1)cnt=a[x];
	else cnt&=a[x];
	dfs(x+1,c+1,cnt);
}
map<int,int>mp;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1,c=1;i<=21;i++)mp[c-1]+1,c*=2;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!mp[a[i]])f=0;
	}
	if(f){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
		return 0;
	}
	if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
		cout<<ans;
		return 0;
	}
	dfs(1,0,-1);
	cout<<ans;
	return 0;
}
