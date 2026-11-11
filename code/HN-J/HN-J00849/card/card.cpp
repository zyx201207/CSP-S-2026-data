#include<bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e5 + 5;
int n,m,arr[maxn];
int ans[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
	}
	for(int i = n;i >= 1;i--){
		if(!ans[arr[i]]){
			ans[arr[i]] = i;
		}
	}
	for(int i = 1;i <= m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
