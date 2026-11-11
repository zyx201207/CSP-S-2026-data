#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+100;
int mp[maxn],a[maxn],will[maxn],ans[maxn];
int n,m;
vector<int>dp[maxn],t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i = 1;i<=n;++i){
		cin>>a[i];
		will[mp[a[i]]] = i;
		mp[a[i]] = i;
	} 
	for(int i = n;i>=1;--i){
		if(!will[i]){
			t = dp[i+1];
			t.push_back(a[i]);
			dp[i] = t;
		}else{
			dp[i] = dp[will[i]]; 
		} 
	}
	for(int i = 1;i<=n;++i){
		int siz = dp[i].size();
		for(int j = 0;j<siz;++j){
			++ans[dp[i][j]];
		}
	}
	for(int i = 1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
} 
/*
%%%sto sto hzk szh tty zjz scx  巨佬们保佑我 J S 不挂分 orz orz%%%
%%%sto sto hzk szh tty zjz scx  巨佬们保佑我 J S 不挂分 orz orz%%%
%%%sto sto hzk szh tty zjz scx  巨佬们保佑我 J S 不挂分 orz orz%%%
%%%sto sto hzk szh tty zjz scx  巨佬们保佑我 J S 不挂分 orz orz%%%
%%%sto sto hzk szh tty zjz scx  巨佬们保佑我 J S 不挂分 orz orz%%% 
*/ 
