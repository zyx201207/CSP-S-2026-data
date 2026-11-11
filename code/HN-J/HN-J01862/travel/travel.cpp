#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w,",stdout);
	
	string a,b,c,d;
	int h=0;
	cin >> a >> c >> b >> d;
	if(a[0]==b[0] && a[1]==b[1])
	{
		if(a[0]!=0 && a[1]!=1 || a[0]!=1 && a[1]!=6)
		{
			cout << "1";
			h=1;
		}
		
	}
	if(h==0)
		cout << "0";
	h=0;
	if(a[0]==b[0] && a[1]==b[1])
	{
		if(a[0]!=0 && a[1]!=1 || a[0]!=1 && a[1]!=6)
		{
			if(c[0]==d[0] && c[1]==d[1])
			{
				cout << "1";
				h=1;
			}
			
		}
	}
	if(h==0)
		cout << "0";
	h=0;
	if(a[0]==b[0] && a[1]==b[1])
	{
		if(a[0]!=0 && a[1]!=1 || a[0]!=1 && a[1]!=6)
		{
			if(c[0]==d[0] && c[1]==d[1])
			{
				if(c[2] >= 'A' && c[2] <= 'C' && d[2] >= 'A' && d[2] <= 'C' || c[2] >= 'D' && c[2] <= 'F' && d[2] >= 'D' && d[2] <= 'F')
				{
					cout << "1";
					h=1;
				}
					
			}
		}
	}
	if(h==0)
		cout << "0";	
	h=0;
	if(a[0]==b[0] && a[1]==b[1])
	{
		if(a[0]!=0 && a[1]!=1 || a[0]!=1 && a[1]!=6)
		{
			if(c[0]==d[0] && c[1]==d[1])
			{
				if(c[2] >= 'A' && c[2] <= 'C' && d[2] >= 'A' && d[2] <= 'C' || c[2] >= 'D' && c[2] <= 'F' && d[2] >= 'D' && d[2] <= 'F')
				{
					if(c[2]=='A' && d[2]=='B' || c[2]=='B' && d[2]=='A' || c[2]=='B' && d[2]=='C' || c[2]=='C' && d[2]=='B' || c[2]=='D' && d[2]=='F' || c[2]=='F' && d[2]=='D')
					{
						cout << "1";
						h=1;
					}
					
				}		
			}
		}
	}
	if(h==0)
		cout << "0";
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
