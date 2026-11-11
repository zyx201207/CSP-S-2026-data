#include<bits/stdc++.h>
#define int long long
using namespace std;
int maxa = 0;
int n,m;
int a[2005];
void dfs(int stap,int x,int sum){
	if(stap > n){
		if(x == m){
			maxa = max(maxa,sum);
		}
		return;
	}
	if(x == 0){
		dfs(stap + 1,x + 1,a[stap]);
		dfs(stap + 1,x,sum);
	}else{
		dfs(stap + 1,x + 1,sum & a[stap]);
		dfs(stap + 1,x,sum);		
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.in","w",stdout);
	cin >>n >>m;
	for(int i = 1;i <= n;i ++){
		cin >>a[i];
	}
	dfs(1,0,0);
	cout <<maxa;
	return 0;
}
