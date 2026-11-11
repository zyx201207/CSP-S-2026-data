#include<bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 5;
long long n,m,arr[maxn],vis[maxn],ans;
bool a_side = 1;
void dfs(long long x,int st,int ii){
	if(st == m){
		ans = max(ans,x);
		return;
	}
	for(int i = ii + 1;i <= n;i++){
		if(!vis[i]){
			vis[i] = 1;
			dfs(x & arr[i],st + 1,i);
			vis[i] = 0;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
		if(arr[i] & (arr[i] + 1) != 0){
			a_side = 0;
		}
	}
	if(a_side){
		sort(arr + 1,arr + 1 + n);
		cout<<arr[n - m + 1];
		return 0;
	}
	for(int i = 1;i <= n;i++){
		dfs(arr[i],1,i);
	}
	cout<<ans;
	return 0;
} 
