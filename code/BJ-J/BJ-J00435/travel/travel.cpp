#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,c1,s2,c2;
    cin>>s1>>c1>>s2>>c2;
    string s="0000";
    if(s1==s2)
    {
        s[0]='1';
        if(c1[0]==c2[0]&&c1[1]==c2[1])
        {

            s[1]='1';
            if(('A'<=c1[2]&&c1[2]<='C'&&'A'<=c2[2]&&c2[2]<='C')||('D'<=c1[2]&&c1[2]<='E'&&'D'<=c2[2]&&c2[2]<='E'))
            {
                s[2]='1';
                if(abs(signed(c1[2]-c2[2]))<=1)
                {
                    s[3]='1';
                }
            }
        }
    }
    cout<<s;
    return 0;
}