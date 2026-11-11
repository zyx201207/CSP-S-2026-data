#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("tavel.in","r",stdin);
	freopen("tavel.out","w",stdout);
	int a,b;
	string c,d;
	cin >> a >> c >> b >> d;
	if(a!=b)
	{
		cout << "0000";
	}
	else if((c[0]!=d[0])||(c[1]!=d[1]))
	{
		cout << "1000";
	}
	else if(((('A'<=c[2])&&(c[2]<='C'))&&(('A'<=d[2])&&(d[2]<='C')))||((('D'<=c[2])&&(c[2]<='E'))&&(('D'<=d[2])&&(d[2]<='E'))))
	{
		if((c[2]+1==d[2])||(d[2]+1==c[2]))
	    {
	    	cout << "1111";
	    }
	    else
	    {
		    cout << "1110";
	    }
	}
	else
	{
		cout << "1100";
	}
	return 0;
}
