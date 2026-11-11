//石阡县文博中学 刘贝宁 GZ-00561
#include <bits/stdc++.h>
using namespace std;
int n,m;
int n_num[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> n_num[i];
	}
	for(int i=1;i<=n;i++){
	cout <<	n-i <<' ';
	}
	 
	return 0;
} 
