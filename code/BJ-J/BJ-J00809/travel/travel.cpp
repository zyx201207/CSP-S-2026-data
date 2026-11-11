#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long c1,c2,a1=0,a2,a3,a4,a5;
    char s1[3],s2[3];
    cin>>c1>>s1[0]>>s1[1]>>s1[2];
    cin>>c2>>s2[0]>>s2[1]>>s2[2];
    if(c1==c2)
    {
        cout<<1;
        a1++;
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            cout<<1;
            a1++;
            if(int(s1[2])>67&&int(s2[2])>67)
            {
                cout<<11;
                a1+=2;
            }
            else if(int(s1[2])<68&&int(s2[2])<68)
            {
                cout<<1;
                a1++;
                if(int(s1[2])-int(s2[2])==1||int(s2[2])-int(s1[2])==1)
                {
                    cout<<1;
                    a1++;
                }
            }
        }
    }
    for(a2=0;a2<4-a1;a2++)
    {
        cout<<0;
    }
    return 0;
}
