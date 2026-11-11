#include <bits/stdc++.h>
using namespace std;
char n[8],x[8],a[8],b[8],num,sum;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<3;i++)
	{
		
	    cin >> n >> x >> a >> b;
	}
	num=x[2];
	sum=b[2];
	if(n==a)
	{
		cout << "1";
		if((x[0]+x[1])==(b[0]+b[1]))
	    {
	    	cout << "1";
		    if((('A'<=num>='C')&&('A'<=sum>='C'))||(('D'<=num>='F')&&('D'<=sum>='F')))
		    {
		    	cout << "1";
		    	if(num=='A'&&sum=='C')
		    	{
		    		cout << "0";
				}
				else
				{
					cout << "1";
				}
			}
			else
			{
				cout << "00";
			}
	    }
	    else
	    {
	    	cout << "000";
	    }
	}
	else
	{
		cout << "0000";
	}
}
