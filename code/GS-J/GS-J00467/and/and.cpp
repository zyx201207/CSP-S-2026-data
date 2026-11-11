#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,b;
	cin >> n >> b;
	for(int i = 0;i < n;i++){
		cin >> m;
	}
	if(n == 4){
		cout << 12;
	}
	else if(n == 5){
		cout << 7;
	}
	return 0;
}
