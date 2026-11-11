#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int z(int a)
{
	string b;
	if(a!=0)
	{
	    if(a%2==1)
	    {
        	a=(a-1)/2;
        	b='1'+b;
	       	z(a);
	    }
	    else
	    {
        	a=a/2;
        	b='0'+b;
	        z(a);
        }
    }
}

int main()
{
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
    int a,b,e;
    cin >> a >> b;
    int c[a];
    for(int d=0;d<a;d++)
    {
    	cin >> c[d];
	}
	e=c[0];
	for(int d=1;d<a;d++)
	{
		if(c[d]<c[d-1])
		{
			e=c[d];
		}
	}
	cout << e;
	return 0;
}
