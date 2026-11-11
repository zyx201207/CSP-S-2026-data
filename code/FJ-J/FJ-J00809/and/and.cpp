#include <bits/stdc++.h>
using namespace std;
int n,m,a[200008],ma=-1;
int ans[200008];
void dfs(int i,int cnt){
	if(i>n){
		return ;
	}
	if(cnt>m){
		int s=INT_MAX;
		for(int i=1;i<cnt;i++){
			s&=ans[i];
		}
		ma=max(ma,s);
		return ;
	}
	ans[cnt]=a[i];
	dfs(i+1,cnt+1);
	ans[cnt]=INT_MAX;
	dfs(i+1,cnt);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(0,0);
	cout<<ma;
	return 0;
} 
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
