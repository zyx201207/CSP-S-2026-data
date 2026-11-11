#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
bool has(int x) {
	for (int i=1;i<=v.size();i++) {
		if (v[i]==x) return true;
	}
	return false;
} 
int main (){
	freopen ("card.in","r",stdin);
	freopen ("card.out","w",stdout);
	int n,m;
	cin > n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) {
		vector<int> v;
		if (!has(a[i])) v.push_back(a[i]);
		else {
			
		}
	}
	return 0;
}
