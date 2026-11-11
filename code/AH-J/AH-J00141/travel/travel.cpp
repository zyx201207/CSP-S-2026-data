#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s,s1;
    long long a,b;
    cin>>a>>s>>b>>s1;
    if(a==b) cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    int as=s[0]+s[1];
    int bs=s1[0]+s1[1];
    if(as==bs)
    {
        cout<<"1";
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if(s[3]<=67&&s1[3]<=67||s[3]>67&&s1[3]>67) cout<<"1";
    else
    {
        cout<<"00";
    }
    if(s[4]<=67&&s1[4]<=67||s[4]>67&&s1[4]>67) cout<<"1";
    else
    {
        cout<<"0";
    }
    return 0;
}
