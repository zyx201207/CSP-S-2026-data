#include<bits/stdc++.h>
using namespace std;
const int N =200005;
long long a1[N],a2[N];
char b1[N],b2[N];
long long ans;
long long yb;
bool flag=1;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a1[i]>>b1[i];
        yb+=a1[i];
    }
    for(int i=1;i<=n;i++)
    {
        a2[i]=a1[n+1-i];
        b2[i]=b1[n+1-i];
    }
    int lb=1,rb=1,ls=a1[1],rs=a2[1];
    while(flag)
    {

        if(ls==0)
        {
            lb++;
            ls=a1[lb];
        }
        if(rs==0)
        {
            rb++;
            rs=a2[rb];
        }
        if(b1[lb]==b2[rb])
        {
            if(ls>rs)
            {
                ls-=rs;
                rs=0;
            }
            else
            {
                rs-=ls;
                ls=0;
            }
        }

        else
        {
            if(ls>rs)
            {
                ans+=min(ls,rs);
                ls-=rs;
                rs=0;
            }
            else
            {
                ans+=min(rs,ls);
                rs-=ls;
                ls=0;
            }
        }
        if(lb>=n||rb>=n)
        {
            flag=0;
        }
    }
    cout<<(ans+1)/2;
    return 0;
}
