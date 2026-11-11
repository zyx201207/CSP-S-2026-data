#include<bits/stdc++.h>
using namespace std;
int a=0,b=0,c=0,d=0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    int n=a,m=c,cnt1,cnt2;
    while(n>0&&m>0)
    {
        cnt1++;
        n/=10;
        m/=10;
    }
    n=1;
    m=a;
    while(n>0&&m>0)
    {
        if(n%10==m%10)
        {
            cnt2++;
        }
        n/=10;
        m/=10;
    }
    if(cnt1==cnt2)
    {
        cout<<1;
        n=b/10;
        m=d/10;
        cnt1=0;
        cnt2=0;
        while(n>0&&m>0)
        {
            cnt1++;
            n/=10;
            m/=10;
        }
        n=b/10;
        m=d/10;
        while(n>0&&m>0)
        {
            if(n%10==m%10)
            {
                cnt2++;
            }
            n/=10;
            m/=10;
        }
        if(cnt1==cnt2)
        {

            cout<<1;
            if((b%10>=65&&b%10<=67&&d%10>=65&&d%10<=67)||(b%10>=68&&b%10<=69&&d%10>=68&&d%10<=69))
            {
                cout<<1;
                if(b%10+1==d%10||b%10-1==d%10)
                {
                    cout<<1;
                }
                else
                {
                    cout<<"0";
                }
            }
            else
            {
                cout<<"00";
                return 0;
            }
        }
        else
        {
            cout<<"000";
            return 0;
        }
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    
    return 0;
}