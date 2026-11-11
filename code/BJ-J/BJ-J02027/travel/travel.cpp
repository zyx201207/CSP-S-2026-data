#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define int ll
map<char,int>mp;
signed main()
{
    string a,b;
    string s1,s2;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>s1>>b>>s2;
    string x=s1.substr(0,2);
    string y=s2.substr(0,2);
    char i=s1[2],j=s2[2];
    mp['A']=1;
    mp['B']=2;
    mp['C']=3;
    mp['D']=4;
    mp['E']=5;
    if(a==b)
    {
        cout<<1;
        if(x==y)
        {
            cout<<1;
            if(('A'<=i&&i<='C'&&'A'<=j&&j<='C')||('D'<=i&&i<='F'&&'D'<=j&&j<='F'))
            {
                cout<<1;
                if(abs(mp[i]-mp[j])==1) cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
