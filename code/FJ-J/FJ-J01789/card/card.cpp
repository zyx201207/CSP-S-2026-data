#include <bits/stdc++.h>

using namespace std;

int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i=m;i>=1;i--) cout << i << ' ';
	return 0;
}