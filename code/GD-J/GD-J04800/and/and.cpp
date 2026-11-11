#include<bits/stdc++.h>
using namespace std;
int t,k;
int b[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> t >> k;
	int k = 0;	
	for(int i = 1;i <= t;i++){
		cin >> b[i];
		if(b[i] > k) k= b[i];
	}
	cout << k;
	return 0;
}
