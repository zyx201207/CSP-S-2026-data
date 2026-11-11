#include<bits/stdc++.h>
using namespace std;
string cx,sx,cy,sy,ss;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cx>>sx>>cy>>sy;
    if(cx!=cy)
    {
        cout<<"0000";
        return 0;
    }
    else
    {
        ss+="1";
        long long a=0,b=0;
        a=(sx[0]-'0')*10+(sx[1]-'0');
        b=(sy[0]-'0')*10+(sy[1]-'0');
        if(a==b)
		{
			ss+="1";
			if(sx[2]<='C'&&sy[2]<='C')
			{
				ss+="1";
				if(!(sx[2]=='C'&&sy[2]=='A'||sx[2]=='C'&&sy[2]=='A'))ss+="1";
				else ss+="0";
			}
			else if(sx[2]>'C'&&sy[2]>'C')ss+="11";
			else ss+="00";
		}
        else ss+="000";
        cout<<ss;
    }
    return 0;
}

