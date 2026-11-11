#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vector<ll>a(n);
	for(int i=1;i<m;i++)a.front()&=a[i];
	cout<<a.front()<<'\n';
	return 0;
}
