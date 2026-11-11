#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn = INT_MIN;
long long arr[200005];
void dfs(int k,int best,int last,int g){
	if(k == m){
		if(best > maxn){
			maxn = best;
		}
		return ;
	}
	for(int i = last+1;i < n;i++){
		if(i != g){
			dfs(k+1,min(arr[g],arr[i]),i,i);
		}
	}
}
int main(){
	cin.tie();
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
	}
	for(int i = 0;i < n;i++){
		dfs(1,0,0,i);
	}
	cout << maxn;
	return 0;
}
