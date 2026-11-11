#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s;
    getline(cin,s);
    vector<int>v;
    for(int i=0;i<4;i++)
    {
        v[i]=0;
    }
        for(int i=0;i<s.size();i++)
    {
        if(s[0]==s[7] && s[1]==s[8])
        {
            v[0]=1;
            if(s[3]==s[10] && s[4]==s[11])
            {
                v[1]=1;
                if(((s[5]=='A'|| s[5]=='B' || s[5]=='c') && (s[12]=='A'|| s[12]=='B' || s[12]=='C') || ((s[5]=='D' ||s[5]=='F')) && (s[12]=='D'|| s[12]=='F')) && s[5]!=s[12])
                   {
                       v[2]=1;
                       if(((s[5]=='A' && s[12]=='B') || (s[5]=='B' && s[12]=='C') || (s[5]=='D' && s[12]=='F'))&& (a[5]!=a[12])) v[3]=1;
                   }
            }
        }

    }
    for(int i=0;i<4;i++)
    {
        cout<<v[i];
    }
    return 0;
}
