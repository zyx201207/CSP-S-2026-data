#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,maxn = 0;
bool vis[500500];
int a[500500];
void dfs(int x,int sum,int s){
	if(x >= m){
		maxn = max(maxn,sum);
	}
	for(int i = s;i <= n;i++){
		if(!vis[i]){
			vis[i] = true;
			if(sum == 0 && x == 0){
				dfs(x + 1,a[i],i);
			}else{
				dfs(x + 1,sum & a[i],i);
			}
			vis[i] = false;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld",&n);
	if(n <= 20){
		scanf("%lld",&m);
		for(int i = 1;i <= n;i++){
			cin>>a[i];
		}
		dfs(0,0,1);
		cout<<maxn;
	}else if(n <= 2000){
		scanf("%lld",&m);
		for(int i = 1;i <= n;i++){
			cin>>a[i];
		}
		if(m == 1){
			for(int i = 1;i <= n;i++){
				maxn = max(a[i],maxn);
			}
			cout<<maxn;
		}else if(m == n){
			maxn = a[1];
			for(int i = 2;i <= n;i++){
				maxn = maxn & a[i];
			}
			cout<<maxn;
		}else{
			for(int i = 1;i <= n;i++){
				for(int j = 1;j <= n;j++){
					if(i == j) continue;
					maxn = max(maxn,a[i] & a[j]);
				}
			}
			cout<<maxn;
		}
	}else{
		scanf("%lld",&m);
		for(int i = 1;i <= n;i++){
			cin>>a[i];
			maxn = max(a[i],maxn);
		}
		cout<<maxn;
	}
	return 0;
}
