#include<bits/stdc++.h>
using namespace std;
int a,b;
string a1,b1;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>a1;
    cin>>b>>b1;
    if(a==b)
        cout<<1;
    else
    {
        cout<<"0000";
        return 0;
    }
    string pa,pb;
    int ka,kb;
    for(int i=0;i<max(a1.size(),b1.size());i++)
    {
        if(a1[i]>='0'&&a1[i]<='9')
        {
            pa+=a1[i];
            ka=i;
        }

        if(b1[i]>='0'&&b1[i]<='9')
        {
            pb+=b1[i];
            kb=i;
        }
    }
    if(pa==pb)
        cout<<1;
    else
    {
        cout<<"000";
        return 0;
    }

    if(a1[a1.size()-1]>='A'&&a1[a1.size()-1]<='C'&&b1[a1.size()-1]>='A'&&b1[b1.size()-1]<='C')
        cout<<1;
    else if((a1[a1.size()-1]=='D'||a1[a1.size()-1]=='F')&&(b1[a1.size()-1]=='D'||b1[b1.size()-1]=='F'))
    {
        cout<<11;
        return 0;
    }

    else
        {
        cout<<"00";
        return 0;
    }

    if(a1[a1.size()-1]-1==b1[a1.size()-1]||a1[a1.size()-1]+1==b1[a1.size()-1])
        cout<<1;
    else
        cout<<0;
    return 0;
}