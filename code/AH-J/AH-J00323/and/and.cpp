#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+10;
int a[N];
int n,m;
int maxx = 0;
void dfs(int step,int sum,int e){
	if(step == n + 1){
		if(e == m + 1){
			maxx = max(maxx,sum);
		}
	}else{
		//int k = sum&a[step];
		//cout<<k<<" ";
		dfs(step+1,sum&a[step],e + 1);
		dfs(step+1,sum,e);
		
	}
	
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	int ans = 0;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		ans = max(ans,a[i]);
	}
	int y = a[1];
	if(m == 1){
		cout<<ans;
		return 0;
	}else if(m == n){
		for(int i = 2;i <= n;i ++){
			y = y & a[i];
		}
		cout<<y;
		return 0;
	}
	dfs(1,a[1],1);
	cout<<maxx;
	
	return 0;
}


