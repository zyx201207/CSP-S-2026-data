#include<bits/stdc++.h>
using namespace std;
string r,rr,x,xx;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>r>>rr>>x>>xx;
    char rrr=rr[rr.size()-1];
    char xxx=xx[xx.size()-1];
    if(r==x)
    {
		cout<<1;
		if(rr[0]==xx[0]&&rr[1]==xx[1])
        {
	    	cout<<1;
	    	if(rrr>='A'&&rrr<='C')
             {
                 if(xxx>='A'&&xxx<='C')
                 {
                    cout<<1;
                    if(xxx-'0'==rrr-'0'+1||xxx-'0'==rrr-'0'-1)
                    {
                        cout<<1;
                    }
                    else cout<<'0';
                }
                else cout<<"00";
            }
            if(rrr>='D'&&rrr<='F')
            {
                if(xxx>='D'&&xxx<='F')
                {
                    cout<<1;
                    if(xxx-'0'==rrr-'0'+2||xxx-'0'==rrr-'0'-2)
                    {

                        cout<<1;
                    }
                    else cout<<'0';
                }
                else cout<<"00";
            }
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
