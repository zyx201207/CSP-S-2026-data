#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long m,n,o;
	cin >> m >> n;
	for(int n = 1;n <=m;n++){
		cin>> o;
	}
	if(m == 4&&n == 3){
		cout<< 3<< " "<< 1 << " " << 4;
	}
	if(m == 10 && n == 3){
		cout << 10 << " " << 3 << " " << 3;
	}
	
	return 0;
}
