#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	int s[200005];
	for(int i=0;i<n;i++){
		cin >> s[i];
	}
	sort(s,s+n);
	cout << s[n/2];
	return 0;
}
