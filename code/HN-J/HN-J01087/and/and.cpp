#include <bits/stdc++.h>
using namespace std;
const int N=2*100005;
int n, m;
long long a[N];
long long maxa=-1;

void dfs(int it,int c,long long ad){
	if (c==0){
//		cout << it << ' ' << c << ' ' << ad << endl;
		maxa=max(maxa, ad);
		return;
	}
	for (int i=it+1;i<n-c+1;i++){
//		cout << it << ' ' << c << ' ' << ad << endl;
		dfs(i,c-1,ad&a[i]);
	}
}

int main(){
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for (int i=0;i<n;i++) cin >> a[i];
		
	for (int i=0;i<n-m;i++){
		dfs(i,m-1,a[i]);
	}
	
	cout << maxa;
	
	return 0;
}
