#include<bits/stdc++.h>
using namespace std;

int main()
{
	 freopen("travel.in","r",stdin);
	 freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int a,b;
	a = (c1[0] - '0') *10 +(c1[1] - '0');
	b = (c2[0] - '0') *10 +(c2[1] - '0');
	if(a== b){
		cout << "1";
	}
	else
	{
		cout << "0000";
		return 0;
	}
	int c,d;
	c = (s1[0]-'0') *10 + (s1[1 ]- '0');
	d = (s2[0]-'0') *10 + (s2[1] - '0');
	if(c != d)
	{
		cout << "000";
		return 0;
	}
	else
	{
		if( c ==d)
		{
			cout << "1";
		}
		if(s1[2] <= 'C' && s1[2]>= 'A'&&s2[2] <= 'C' && s2[2]>= 'A')
		{
			cout << '1';
		}
		else if (s1[2] <= 'F' && s1[2]>= 'D'&&s2[2] <= 'F' && s2[2]>= 'D')
		{
			cout << '1';
		}
		else
		{
			cout << "00";
			return 0;
		}
		if(abs(s1[2] - s2[2]) == 1)
		{
			if(s1[2] != 'C' && s2[2] != 'C')
			{
				cout << "1";
			}
		}
		else
		{
			cout << "0";
		}
		
	}
	
	 
	
	
	
	
	
	return 0;
 } 
