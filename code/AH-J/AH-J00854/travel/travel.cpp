#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)cout<<"0000";
    else
    {
        string t1;
        t1+=s1[0]+s1[1];
        string t2;
        t2+=s2[0]+s2[1];
        if(t1!=t2)cout<<"1000";
        else
        {
            char c1=s1[2];
            char c2=s2[2];
            if(c1<='C'&&c2<='C'||c1>='D'&&c2>='D')
            {
                if(c1==c2+1||c2==c1+1)cout<<"1111";
                else cout<<"1110";
            }
            else
            {
                cout<<"1100";
            }
        }
    }
    return 0;
}
