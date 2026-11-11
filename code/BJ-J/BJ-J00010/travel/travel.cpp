#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f1=false,f2=false,f3=false;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        f1=true;
        cout<<1;
    }
    else cout<<0;
    if(f1==false) cout<<0;
    else
    {
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            f2=true;
            cout<<1;
        }
        else cout<<0;
    }
    char ch1=s1[2],ch2=s2[2];
    if(f2==false) cout<<0;
    else
    {
        if(ch1<='C'&&ch2<='C'||ch1>'C'&&ch2>'C')
        {
            f3=true;
            cout<<1;
        }
        else cout<<0;
    }
    if(f3==false) cout<<0;
    else
    {
        int t1=int(ch1);
        int t2=int(ch2);
        if(abs(t1-t2)==1) cout<<1;
        else cout<<0;
    }
    return 0;
}