#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m,t=INT_MAX;
	cin>>n>>m;
	int f[n];
	for(int i=0;i<n;i++){
		cin>>f[i];
	}
	sort(f, f+n);
	for(int i=n-1;i>=n-m;i--){
		t&=f[i];
	}
	cout<<t;
	return 0;
}

