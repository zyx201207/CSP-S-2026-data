#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,m;
long long a[N],ans = -1,last[N],maxx = -1;
bool use[N];

void dfs(int x){
	if(x == m){
		maxx = max(maxx,ans);
		return;
	}
	
	for(int i = 1; i <= n; i++){
		if(ans == -1 && !use[i]){
			last[x] = ans;
			ans = a[i];
			use[i] = true;
			dfs(x+1);
			use[i] = false;
			ans = last[x];
		}
		else if(!use[i]){
			last[x] = ans;
			ans &= a[i];
			use[i] = true;
			dfs(x+1);
			use[i] = false;
			ans = last[x];
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	dfs(0);
	cout << maxx;
	return 0;
}
