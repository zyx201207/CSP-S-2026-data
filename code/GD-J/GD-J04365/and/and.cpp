#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e5+50;
int a[N];

int dp[N];
int num;
int maxn=0;int n,m;
void dfs(int now,int cnt,int w){
	if(now>n)return;
	if(cnt>m)return;
	if(cnt!=1)maxn=max(w,maxn);
	for(int i=now+1;i<=n;i++){
		int y=w;
		w&=a[i];
		dfs(i,cnt+1,w);
		w=y;
	} 
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i]; 
	for(int i=1;i<=n;i++)dfs(i,1,a[i]);
	cout<<maxn;
	return 0;
}/*4 12
3 15 12 12*//*
5 3
31 3 1 15 7
*/
