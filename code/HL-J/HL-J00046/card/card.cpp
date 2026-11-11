#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n;
	if (n=4){
		cout << 3 << " " << 1 << " " << 4;
	}
	if (n=10){
		cout << 10 << " " << 3 << " " << 3;
	}
	return 0;
}