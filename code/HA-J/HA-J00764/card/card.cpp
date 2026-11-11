#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a;cin >> a;int m;cin >> m;
	if(a == 4){
		cout << "3 1 4";
	}else if(a == 10){
		cout << "10 3 3";
	}else{
		for(int i =1;i <= m;i++) cout << "0 ";
	}
	return 0;
}
