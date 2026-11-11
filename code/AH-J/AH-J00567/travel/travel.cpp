#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<"1";
        int a=s1[0]-'0';a*=10;a+=s1[1]-'0';
        int b=s2[0]-'0';b*=10;b+=s2[1]-'0';
        if(a==b)
        {
            cout<<"1";
            if(s1[2]<='C'&&s2[2]<='C')
            {
                cout<<"1";
                if(s1[2]+1==s2[2]||s1[2]==s2[2]+1) cout<<"1";
                else cout<<"0";
            }
            else if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='D'&&s2[2]=='F')) cout<<"11";
            else cout<<"00";

        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
