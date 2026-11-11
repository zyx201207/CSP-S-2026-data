#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d;
	bool x=1,y=1,z=1,q=1;
	cin >> a >> b >> c >> d;
	if(a != c){
		cout << "0000\n";
		return 0;
	}
	if(b[0] != d[0] || b[1] != d[1]){
		cout << "1000\n";
		return 0;
	}
	if(b[2] == 'D' || d[2] == 'D'){
		if(b[2] == 'F' || d[2] == 'F'){
			cout << "1111\n";
		}
		else cout << "1100\n";
	}
	else{
		if(b[2] == 'F' || d[2] == 'F'){
			cout << "1100\n";
			return 0;
		}
		if(b[2] == d[2]+1 || d[2] == b[2]+1){
			cout << "1111\n";
		}
		else cout << "1110\n";
	}
	return 0;
}
