#include<bits/stdc++.h>
using namespace std;
long long a[6][20] , l , k;
string s , ss , sss , ssss;
long long x , xx , xxx , xxxx;
char c , cc;
int main()
{
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	cin >> s >> ss >> sss >> ssss;
	for(int i = 0; i <= 1; i++)
	{
		x = x * 10 + (s[i] - '0');
		xxx = xxx * 10 + (sss[i] - '0');
	}
	if(x != xxx)
	{
		cout << "0000";
		return 0;
	}
	else cout << "1";
	for(int i = 0; i <= 1; i++)
	{
		xx = xx * 10 + (ss[i] - '0');
		xxxx = xxxx * 10 + (ssss[i] - '0');
	}
	c = ss[2] , cc = ssss[2];
	if(xx == xxxx) 
	{
		cout << "1";
		if((c >= 'A' && c <= 'C' && cc >= 'A' && cc <= 'C') || (c >= 'D' && c <= 'F' && cc >= 'D' && cc <= 'F')) cout << "1";
		else cout << "0";
	}
	else cout << "00";
	if(c == 'C' && cc == 'D') 
	{
		cout << "0";
		return 0;
	}
	if(max(c , cc) - min(c , cc) == 1 && xx == xxxx)
		cout << "1";
	else cout << "0";
	return 0;
} 
