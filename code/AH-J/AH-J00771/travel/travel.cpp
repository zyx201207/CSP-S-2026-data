#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int cnt,ans,a;
int main()
{   
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<=1;i++)
    {
        if(c1[i]==c2[i])
        {
            cnt++;
        }
        if(cnt==2)
        {    
            a++;
            for(int j=0;j<=1;j++)
            {
                if(s1[j]==s2[j])
                {
                    ans++;
                }
                if(ans==2)
                {
                    a++;
                }  
            }
        }
    }
    b=4-a;
    while(a>0)
    { 
        cout<<1;
        a-=1;
    }
    while(b>0)
    { 
        cout<<0;
        b-=1;
    }
    return 0;
}
