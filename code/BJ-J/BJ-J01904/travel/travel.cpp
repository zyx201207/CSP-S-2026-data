#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c1,c2;
string s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<"0000";
        return 0;
    }
    if(s1[0]!=s2[0]||s1[1]!=s2[1])
    {
        cout<<"1000";
        return 0;
    }
    //cout<<s1[2]<<s2[2];
    ll p1,p2;
    if('A'<=s1[2]&&s1[2]<='C')p1=1;
    else p1=2;
    if('A'<=s2[2]&&s2[2]<='C')p2=1;
    else p2=2;
    //cout<<p1<<" "<<p2;
    if(p1!=p2)
    {
        cout<<"1100";
        return 0;
    }
    if((s1[2]=='A'&&s2[2]=='B')||(s2[2]=='A'&&s1[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s2[2]=='B'&&s1[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F'))
    {
        cout<<"1111";
        return 0;
    }
    cout<<"1110";
    return 0;
}
