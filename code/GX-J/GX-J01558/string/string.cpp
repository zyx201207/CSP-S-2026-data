#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,b,s[100000000001],x=0,y=0,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        for(int j=1;j<=a;j++)
        {
            s[y]+=b;
        }
        y++;
        x+=a;
    }
    y=1;
    if(a%2==0)
    {
        for(int i=a/2+1;i<=a;i++)
        {
            if(s[i]!=s[i-y])
            {
                sum++;
                y++;
            }
        }
    }
    else
    {
        for(int i=a/2+2;i<=a;i++)
        {
            if(s[i]!=s[i-y-1])
            {
                sum++;
                y++;
            }
        }
    }
    cout<<sum;
    return 0;
}
