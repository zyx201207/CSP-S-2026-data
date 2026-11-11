#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string rx,rs,xx,xs;
    cin>>rx>>rs>>xx>>xs;
    int d1=(rx[0]-'0')*10+(rx[1]-'0');
    int d2=(xx[0]-'0')*10+(xx[1]-'0');
    if(d1==d2)
    {
        cout<<1;
        if(rs[0]==xs[0]&&rs[1]==xs[1])
        {
        	cout<<"1";
        	if(rs[2]=='A'||rs[2]=='B'||rs[2]=='C')
        	{

        		if(xs[2]=='A'||xs[2]=='B'||xs[2]=='C')
        		{
        			cout<<"1";
        			int cs=xs[2]-rs[2];
        			if(abs(cs)==1)
        			{
        				cout<<"1";
					}
					else
					{

						cout<<"0";
					}
				}
				else
				{

					cout<<"00";
				}
			}
			else if(rs[2]=='D'||rs[2]=='E')
			{

				if(xs[2]=='D'||xs[2]=='E')
				{
					cout<<"1";
					int cs=xs[2]-rs[2];
        			if(abs(cs)==1)
        			{
        				cout<<"1";
					}
					else
					{
						cout<<"0";
					}
				}
				else
				{
					cout<<"00";
				 }
			}
		}
		else
		{
			cout<<"000";
		}
    }
    else{
        cout<<"0000";
    }
    return 0;
}
