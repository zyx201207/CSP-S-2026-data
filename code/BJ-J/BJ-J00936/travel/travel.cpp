#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
        cout<<1;
    else
        cout<<0;

    ll r=(s1[0]-'0')*10+(s1[1]-'0');
    ll x=(s2[0]-'0')*10+(s2[1]-'0');
    if((c1==c2)&&(r==x))
        cout<<1;
    else
        cout<<0;

    set<char> le,ri;
    le.insert('A');
    le.insert('B');
    le.insert('C');
    ri.insert('D');
    ri.insert('F');
    bool q3=(le.count(s1[2])&&le.count(s2[2]))||(ri.count(s1[2])&&ri.count(s2[2]));
    if((c1==c2)&&(r==x)&&q3)
        cout<<1;
    else
        cout<<0;

    bool q4=(s1[2]=='A'&&s2[2]=='B')||
            (s1[2]=='B'&&s2[2]=='A')||
            (s1[2]=='B'&&s2[2]=='C')||
            (s1[2]=='C'&&s2[2]=='B')||
            (s1[2]=='D'&&s2[2]=='F')||
            (s1[2]=='F'&&s2[2]=='D');
    if((c1==c2)&&(r==x)&&q3&&q4)
        cout<<1;
    else
        cout<<0;
    return 0;
}
