#include <bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int n,m,k;
	int t;
	cin << t;
	for (int T = 0;T < t;T++)
	{
		cin << n << k;
		for (int i = 1;i < n;i++) cin >> m >> k;
		cout << T << endl;
	} 
	return 0;
}
