#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) ans+="1";
    else
    {
        cout<<"0000";
        return 0;
    }
    int yyy=(s1[0]-'0')*10+(s1[1]-'0');
    int yyy1=(s2[0]-'0')*10+(s2[1]-'0');
    char dhz=s1[2];
    char dhz1=s2[2];
    if(yyy==yyy1) ans+="1";
    else
    {
        cout<<"1000";
        return 0;
    }
    if((dhz=='A'&&dhz1=='B')||(dhz=='A'&&dhz1=='C')||(dhz1=='A'&&dhz=='B')||(dhz1=='A'&&dhz=='C')||(dhz=='D'&&dhz1=='F')||(dhz=='F'&&dhz1=='D'))
        ans+="1";
    else
    {
        cout<<"1100";
        return 0;
    }
    if((dhz=='A'&&dhz1=='B')||(dhz1=='A'&&dhz=='B')||(dhz=='D'&&dhz1=='F')||(dhz=='F'&&dhz1=='D'))
        ans+="1";
    else ans+="0";
    cout<<ans;
    return 0;
}
