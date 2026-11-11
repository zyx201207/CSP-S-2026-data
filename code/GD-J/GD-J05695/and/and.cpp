#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	vector<int> a;
	for(int i=1;i<=n;i++){
		cin>>x;
		a.push_back(x);
	}sort(a.begin(),a.end());
	cout<<a[n/2];
	return 0;
}
