#include <bits/stdc++.h>

using namespace std;

string a , b , c , d;

int find(char c)
{
	if(c == 'A' || c == 'B' || c == 'C') return 0;
	return 1;
}

bool check(char s , char t)
{
	int num1 = s - 'A' , num2 = t - 'A';
	if(abs(num1 - num2) == 1) return 1;
	return 0;
}

int main()
{
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> a >> b >> c >> d;
	int flag = 1;
	
	if(a != c) flag = 0;
	cout << flag;
	if(b[0] != d[0] || b[1] != d[1]) flag = 0;
	cout << flag;
	if(find(b[2]) != find(d[2])) flag = 0;
	cout << flag;
	if(!check(b[2] , d[2])) flag = 0;
	cout << flag;
	
	return 0;
}
/*
02 01A 02 01B
*/
