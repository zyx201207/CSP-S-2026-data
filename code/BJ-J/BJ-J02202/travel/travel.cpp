#include<bits/stdc++.h>
using  namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,a2,s1sum=0,s2sum=0;
    char c1[4];
    char c2[4];
    cin>>a1;
    for(int i=1;i<=3;i++)
    {
        cin>>c1[i];
    }
    for(int i=1;i<=3;i++)
    {
        cin>>c2[i];
    }
    if(a1==a2)
    {
        if(c1[1]+c1[2]==c2[1]+c2[2])
        {
            s1sum=int(c1[3]);
            s2sum=int(c2[3]);
            if(s2sum==s1sum+1||s2sum==s1sum-1)
            {
                cout<<"1111";return 0;
            }
            else cout<<"1110";return 0;
        }
        else cout<<"1100";return 0;
    }
    else cout<<"0000";return 0;

}
