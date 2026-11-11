#include<bits/stdc++.h>
using namespace std;

void find1(int &l, int &r, vector<int>& arr, int &n, int &m){
	while(r<=n){
		r++;
		if(arr[r]==arr[l]){
			l=r;
		}
	}
}

void solve1(int& n, int& m, vector<int>& arr, vector<int>& ans){
	for(int i=1;i<=n;i++){
		int l=i, r=i;
		while(l<=n){
			find1(l, r, arr, n, m);
			ans[arr[l]]++;
			l++;
			r=l;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin>>n>>m;
	vector<int>arr(n+1, 0);
	vector<int>ans(m+1, 0);
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	solve1(n, m, arr, ans);
	return 0;
}
