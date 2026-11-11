#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
int c,t;
vector<int> v;
int main () {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for (int i=1;i<=t;i++){
		int n,d,x[MAXN];
		cin>>n>>d;
		for (int i=1;i<=n;i++) cin>>x[i];
		v.push_back(n-d-1);
	}
	for (int i=0;i<v.size();i++) cout<<v[i]<<endl;
	return 0;
}
