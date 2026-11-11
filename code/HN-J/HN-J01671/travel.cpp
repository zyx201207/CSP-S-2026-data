#include <bits/stdc++.h>
using namespace std;
main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	int e=char(b[2]),f=char(d[2]);
	if(a==c)
	{
		cout<<1<<endl;
		
		if(b[0]==d[0]&&b[1]==d[1])
		{
		    cout<<"1\n";
		    if(f<=67&&e<=67)
		    {
		    	cout<<"1\n";
		    	if(e-f==1||f-e==1)
		    	    cout<<"1\n";
		        else
		            cout<<0<<endl;
			}
			else if(e>67&&f>67)
			{
		        cout<<1<<endl<<1<<endl;
			}
			else
			    cout<<"0\n"<<"0\n";
	}
	    else cout<<"0\n"<<"0\n"<<"0\n";
	    
	}
	else
	    cout<<"0\n"<<"0\n"<<"0\n"<<"0\n";
	
	return 0;
}
//02 01A 02 01B
