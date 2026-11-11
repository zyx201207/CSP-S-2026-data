#include <bits/stdc++.h>
#define int long long
using namespace std;

string c1,s1,c2,s2;
int ic1,is1,ic2,is2;
int p1,p2;

signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    ic1=10*(c1[0]-'0')+(c1[1]-'0');
    is1=10*(s1[0]-'0')+(s1[1]-'0');
    ic2=10*(c2[0]-'0')+(c2[1]-'0');
    is2=10*(s2[0]-'0')+(s2[1]-'0');
    p1=s1[2]-'A';
    if(p1==5) p1--;
    p2=s2[2]-'A';
    if(p2==5) p2--;
    if(ic1!=ic2)
    {
        cout<<"0000";
        return 0;
    }
    if(is1!=is2)
    {
        cout<<"1000";
        return 0;
    }
    if(((p1<=2)&&(p2>=3))||((p1>=3)&&p2<=2))
    {
        cout<<"1100";
        return 0;
    }
    if(abs(p1-p2)!=1)
    {
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}
