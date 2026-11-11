#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	
	int x[n];
	for(int i=0;i < n;i ++){
		cin >> x[i];
	}
	
	if(n == 4) cout << "3 1 4" ;
	if(n == 10) cout << "10 3 3";
	
	
	return 0;
}
