#include<bits/stdc++.h>
using namespace std;
int n,m,a[200000],ans = 0;
int y = INT_MAX,sum = 0;
void dfs(int deep,int i,int y){
	if(deep == m){
		ans = max(ans,y);
		return;
	}
	if(i == n + 1){
		return;
	}
	dfs(deep + 1,i + 1,(y&a[i]));
	dfs(deep,i + 1,y);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		y = (y&a[i]);
		sum += a[i];
	}
	if(m == 1){
		int x = INT_MAX;
		for(int i = 1;i <= n;i++){
			ans = max(ans,(x&a[i]));
		}
		cout<<ans;
		return 0;
	}
	if(m == 2){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i != j){
					ans = max(ans,(a[i]&a[j]));
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(n <= 20){
		dfs(0,1,INT_MAX);
		cout<<ans;
		return 0;
	}
	ans = INT_MAX;
	sort(a + 1,a + n + 1);
	while(m > 0){
		m--;
		ans = (ans&a[n]);
		n--; 
	}
	cout<<ans;
	return 0;
}
