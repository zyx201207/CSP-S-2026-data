#include <bits/stdc++.h> 
using namespace std;
string a,b,c,d; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	int flag = 0;
	for(int i = 0;i < 2;i++)
	{
		if(a[i] != c[i])
		{
			flag = 1;
		}
	}
	if(flag == 0 && a != "01" && a != "16" && c != "01" && c != "16")
	{
		cout<<1;
	}
	else
	{
		cout << 0;
		flag = 1;
	}
	int fla = 0;
	for(int i = 0;i < 2;i++)
	{
		if(b[i] != d[i])
		{
			fla = 1;
		}
	}
	if(flag == 0 && fla == 0)
	{
		cout << 1; 
	}
	else
	{
		cout << 0;
	}
	int fl = 0;
	if((b[2] <= 'C' && d[2] <= 'C') || (b[2] > 'C' && d[2] > 'C'))
	{
		if(flag == 0 && fla == 0)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	else
	{
		cout << 0;
		fl = 1;
	}
	int n = b[2]-'0',m = d[2]-'0';
	if((b[2] == 'D' && d[2] == 'F') || (b[2] == 'F' && d[2] == 'D'))
	{
		if(fl == 0&&flag == 0 && fla == 0)
		{
			cout << 1;
			return 0;
		}
	}
	if(abs(n-m) == 1&&fl == 0&&flag == 0 && fla == 0)
	{
		cout << 1; 
	}
	else
	{
		cout << 0;
	}
	return 0;
}
