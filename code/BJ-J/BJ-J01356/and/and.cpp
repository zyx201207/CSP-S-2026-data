#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a;
	for(int i=0;i<n;i++){
		int a1;
		cin>>a1;
		a.push_back(a1);
	}
	sort(a.begin(),a.end()+1);
	cout<<a[n]<<endl;
	return 0;
}