#include<iostream>
#include<string>
using namespace std;
int main()
{
	int a;
	char b[3];
	cin >> a;
	for(int i = 0;i < 3;i++)
	{
		cin >> b[i];
	}
	int c;
	cin >> c;
	char d[3];
	for(int i = 0;i < 3;i++)
	{
		cin >> d[i];
	}
	if(a == c)
	{
		cout << 1;
		if(b[0] == d[0] && b[1] == d[1])
		{
			cout << 1;
			if(b[2]  == 'D' || b[2]  == 'F')
			{
				if(d[2] == 'D' || d[2] == 'F')
				{
					cout << 11;
				}
				else{
					cout << 0 << 0;
					return 0;
				}
			}
			else
			{
				if(d[2] == 'A' || d[2] == 'B' || d[2] == 'C')
				{
					cout << 1;
					if((d[2] == 'A' && (b[2] == 'B'||b[2] == 'C') )||(d[2] == 'B' &&( b[2] == 'C'|| b[2] == 'A'))||(d[2] == 'C' && b[2] == 'B'))cout << 1;return 0;
				} 
				else
				{
					cout << 0 << 0;
					return 0;
				}
	    	}
		}
		else
		{
			cout <<0 << 0 << 0;
			return 0;
		}	
	}
	else
	{
		cout << 0 << 0 << 0 << 0;
	}
}
