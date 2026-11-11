#include<bits/stdc++.h>
using namespace std;
#define Int long long
Int check(char c)
{
    if(c>='A'&&c<='C')
    {
        return 1;
    }
    else{
        return 2;
    }
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s1,s2,t1,t2;
    cin>>s1>>s2>>t1>>t2;
    char c1=s2[0],c2=s2[1],c3=s2[2];
    char h1=t2[0],h2=t2[1],h3=t2[2];
    if(s1==t1)
    {
        cout<<1;
        if(c1==h1&&c2==h2)
        {
            cout<<1;
            Int x=check(c3),y=check(h3);
            if(x==y)
            {
                cout<<1;
                if((x==y&&x==2)||(x==1&&c3=='A'&&h3=='B')||(x==1&&c3=='B'&&h3=='A')||(x==1&&c3=='C'&&h3=='B')||(x==1&&c3=='B'&&h3=='C'))
                {
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
//♿♿♿wow!
