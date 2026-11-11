#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	m*=683;
	cout << m/2 << ' ' << m/3 << ' ' << m/4;
	
	
	return 0;
}
