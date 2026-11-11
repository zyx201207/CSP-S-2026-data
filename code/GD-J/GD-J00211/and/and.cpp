#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+5;
int a[MAXN];
bool cmp[MAXN];
int n,m;
int maxn = 0;
int ans = 0;
void dfs(int cnt,int depth,bool ccmp){
	if(depth == 0){
		maxn = max(maxn,cnt);
		return ;
	}if(ccmp == 0){
		for(int i = 1;i<=n;i++){
			if(!cmp[i]){
				cmp[i] = 1;
				dfs(a[i],depth-1,1);
				cmp[i] = 0;
			}
		}
	}
	for(int i = 1;i<=n;i++){
		if(!cmp[i]){
			cmp[i] = 1;
			dfs(cnt&a[i],depth-1,1);
			cmp[i] = 0;
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
		cin>>a[i];
	dfs(0,m,0);
	cout<<maxn;
	return 0;
}
