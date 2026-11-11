#include <bits/stdc++.h>
using namespace std;

string a1,a2;
string b1,b2;
bool f1,f2,f3,f4;

bool check(char x,char y)
{
	if (x >= 'A' && x <= 'C'){
		return (y >= 'A' && y <= 'C');
	}
	return (y == 'F' || y == 'D');
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if (a1 != b1){
		cout<<"0000\n";
		return 0;
	}
	f1 = 1;
	int a3 = (a2[0] - '0') * 10 + a2[1] - '0';
	int b3 = (b2[0] - '0') * 10 + b2[1] - '0';
	f2 = (bool)(a3 == b3);
	if (f2 && check(a2[2],b2[2])) f3 = 1;
	else f3 = 0;
	if (!check(a2[2],b2[2])) f4 = 0;
	else{
		if (a3 == b3 && abs(a2[2] - b2[2]) == 1) f4 = 1;
		else if (abs(a3 - b3) == 1 && a2[2] == b2[2]) f4 = 1;
		else f4 = 0;
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
