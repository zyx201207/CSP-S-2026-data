#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int> v;
	long long n,m; cin>>n>>m;
	while(n--){
		long long x;cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	cout<<v[m-1];
	return 0;
}
