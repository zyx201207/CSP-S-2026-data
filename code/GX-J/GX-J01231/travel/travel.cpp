#include<bits/stdc++.h>
using namespace std;

int a,b;
string aa,bb;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>aa>>b>>bb;
    if(a!=b)
    {
        cout<<"0000";
        return 0;
    }
    if(a==b);
    {
        cout<<1;
    }
    if(aa[1]!=bb[1]||aa[0]!=bb[0])
    {
        cout<<"000";
        return 0;
    }
    if(aa[1]==bb[1]&&aa[0]==bb[0]);
    {
        cout<<1;
    }
    if(aa[2]<='C'&&bb[2]>'C'||aa[2]>='D'&&bb[2]<'D')
    {
        cout<<"00";
        return 0;
    }
    if((aa[2]<='C'&&bb[2]<='C')||(aa[2]>='D'&&bb[2]>='D'));
    {
        cout<<1;
    }

    if(aa[2]<='C'&&(aa[2]+1==bb[2]||bb[2]+1==aa[2]))
    {
        cout<<1;
        return  0;
    }
    if(aa[2]<='C'&&(aa[2]+2==bb[2]||bb[2]+2==aa[2]))
    {
        cout<<0;
        return 0;
    }
    if(aa[2]>='D')
    {
        cout<<1;
    }
    return 0;
}
