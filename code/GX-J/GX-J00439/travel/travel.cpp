#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >>b >>c >>d;
	if(a == c){
		cout << "1";
	}
	else{
		cout << "0";
	}
	int u = 0;
	for(int i = 0;i < 2;i++){
		if(b[i] != d[i]){
			u++;
		}
	}
	if(u == 0){
		cout << "1";
	}
	if(a[2]=='A'||a[2]=='B'||a[2]=='C'){
		if(c[2] == 'A'||c[2]=='B'||c[2] =='C'){
			cout <<"1";
		}
	}
	else if(a[2] == 'D'||a[2] == 'F'){
		if(c[2] == 'D'||c[2] == 'F'){
			cout <<"1";
		}
	}
	else{
		cout << "0";
	}
	if(a[2]=='A'&&c[2]=='B'){
		cout << "1";
	}
	else if(a[2] == 'B'&&c[2] == 'C'){
		cout << "1";
	}
	else if(a[2] == 'D'&&c[2] == 'F'){
		cout << "1";
	}
	else{
		cout << "0";
	}
	return 0;
}
