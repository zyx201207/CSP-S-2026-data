#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const ll N=;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    ll ans=0;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        ans++;
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            ans++;
            char a=s1[2],b=s2[2];
            if((a=='F'&&b=='D'||(a=='D'&&b=='F'))||(a<='C'&&b<='C'))
            {
                ans++;
                if(abs(a-b)==1)ans++;
            }
        }
    }
    for(ll i=1;i<=4;i++)
    {
        if(ans)
        {
            ans--;
            cout<<1;
        }
        else cout<<0;
    }
    return 0;
}
