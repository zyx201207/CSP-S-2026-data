#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1, s1, c2, s2,a=0,b=0,c=0,d=0;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2)
    {
        a+=1;
        if(s1[1]==s2[1])
        {
            if(s1[2]==s2[2])
            {
                b+=1;
                if((s1[3]>='A'&&s1[3]<='C')&&(s2[3]>='A'&&s2[3]<='C')||(s1[3]='F'||s1[3]='D')&&(s2[3]='F'||s2[3]='D'))
                {
                    c+=1;
                    if(s1[3]+1==s2[3]||s1[3]-1==s2[3])
                    {
                        d+=1;
                    }
                }
            }
        }
    }
    cout << a << b << c << d;
    return 0;
}
