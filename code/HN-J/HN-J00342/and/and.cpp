#include <bits/stdc++.h>
using namespace std;
int a[200005];
int maxn;
int n,m;
void dfs(int num,int c,int i){
	if (i == m){
		for (int j = i+1;j <= n;j++){
			maxn = max(maxn,num&a[j]);
		}
		return;
	}
	for(int j = i+1;j <= n;j++){
		int s = a[j]&num;
		dfs(s,c+1,j);
	} 
} 

int main(){
	freopen(ans.in,'r',stdin);
	freopen(ans.out,'w',stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++){
		dfs(a[i],1,i);
	}
	cout << maxn << endl;
	return 0;
} 
