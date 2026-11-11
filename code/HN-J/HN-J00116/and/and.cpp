#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
long long a[maxn]; 
bool vis[maxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	} 
	long long ans = 0;
	for(int i = 30;i>=0;i--){
		int cnt = 0;
		for(int j = 1;j<=n;j++){
			if((a[j]&(1<<i)) && !vis[j])cnt++;
		}
		if(cnt>=m){
			ans+=(1<<i);
			for(int j = 1;j<=n;j++){
				if(!(a[j]&(1<<i)))vis[j] = 1;
			} 
		}
	}
	cout<<ans;
	return 0;
}
/*
%%%sto sto hzk szh tty zjz scx  巨佬们保佑我 J S 不挂分 orz orz%%%
%%%sto sto hzk szh tty zjz scx  巨佬们保佑我 J S 不挂分 orz orz%%%
%%%sto sto hzk szh tty zjz scx  巨佬们保佑我 J S 不挂分 orz orz%%%
%%%sto sto hzk szh tty zjz scx  巨佬们保佑我 J S 不挂分 orz orz%%%
%%%sto sto hzk szh tty zjz scx  巨佬们保佑我 J S 不挂分 orz orz%%% 
*/ 
