#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1,c2;
    string s1,s2;
    string a,b,n,m;
    int ans=0;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {

        cout<<0000<<endl;
        return 0;
    }
    if(c1==c2)
    {

        ans+=1000;
        for(char c:s1)
        {

            if(s1>='0'&&s1<='9')
            {
                a.push_back();
            }
            if(s1>='A'&&s1<='Z')
            {
                b.push_back();
            }
        }
        for(char c:s2)
        {
            if(s2>='0'&&s2<='9')
            {
                m.push_back();
            }
            if(s1>='A'&&s1<='Z')
            {
                n.push_back();
            }
        }
        if(a==m)
        {
            ans+=100;
            if((b>='A'&&b<='C'&&n>='A'&&n<='C')||(b>='D'&&b<='F'&&n>='D'&&n<='F'))
            {
                ans+=10;
                if(b+'1'==n||b-'1'==n)
                {
                    ans+=1;
                }
            }
        }

    }
    cout<<ans<<endl;
    return 0;
}
