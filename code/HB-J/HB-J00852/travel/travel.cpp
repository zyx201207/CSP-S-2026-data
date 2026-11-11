#include<bits/stdc++.h>
using namespace std;
string c1 , s1 , c2 , s2 ;
int book[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) book[1] = 1;
	//
	string t1 = s1.substr(0,2), t2 = s2.substr(0,2);
	if(t1 == t2 and book[1] == 1) book[2] = 1;
	//
	if(book[2] == 1)
	{
		if(s1[2] >= 'A' and s1[2] <= 'C')
		{
			if(s2[2] >= 'A' and s2[2] <= 'C')
				book[3] = 1;
		}
		else if(s1[2] == 'D' or s1[2] == 'F')
		{
			if(s2[2] == 'D' or s2[2] == 'F')
				book[3] = 1;
		}
	}
	//
	if(book[3] == 1)
	{
		int a = s1[2] - 'A' , b = s2[2] - 'A';
		if(abs(a-b) == 1)
			book[4] = 1;
	}
	//
	for(int i = 1 ; i <= 4 ; i ++)
		cout << book[i];
	return 0;
}
