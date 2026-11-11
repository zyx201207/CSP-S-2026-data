#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int tonum(string x)
{
    int ans=0;
    for(int i=0;i<x.length();++i)
        if('0'<=x[i] && x[i]<='9')
            ans=ans*10+x[i]-'0';
    return ans;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int x1,x2,c1,c2;
    char s1,s2;
    string s;
    cin>>s;
    x1=tonum(s);
    cin>>s;
    c1=tonum(s);
    s1=s[2];

    cin>>s;
    x2=tonum(s);
    cin>>s;
    c2=tonum(s);
    s2=s[2];

    if(x1==x2)
    {
        cout<<1;
        if(c1==c2)
        {
            cout<<1;
            if((s1<='C' && s2<='C') || (s1>'C' && s2>'C'))
            {
                cout<<1;
                if(abs(s1-s2)==1)
                    cout<<1;
                else
                    cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";


    fclose(stdin);
    fclose(stdout);
    return 0;
}
