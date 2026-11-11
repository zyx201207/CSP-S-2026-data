#include <bits/stdc++.h>
using namespace std;
int n[5];
string rb,xb,ra,xa;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ra>>rb>>xa>>xb;
    if(ra==xa)
    {
        n[1]=1;
        if(rb[0]==xb[0]&&rb[1]==xb[1])
        {
            n[2]=1;
            if(rb[2]>='D'&&xb[2]>='D'||rb[2]<='C'&&xb[2]<='C')
            {
                n[3]=1;
                if(abs(rb[2]-xb[2])==1)
                {
                    n[4]=1;
                }
            }
        }
    }
    for(int i=1;i<=4;i++)
    {
        cout<<n[i];
    }
	return 0;
}
