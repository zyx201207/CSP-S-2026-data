#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>s1>>s2;
    if(c1==s1) cout<<"1";
    else cout<<"0";
    string a,b;
    bool fa,fb;
    char c,d;
    for(int i=0;i<=c2.size()-1;i++)
    {
        if(c2[i]>='0'&&c2[i]<='9')
        {
            a+=c2[i];
        }
        else
            {
                c=c2[i];
                if(c2[i]=='A'||c2[i]=='B'||c2[i]=='C')
                {
                    fa=1;
                }
                else
                {
                    fa=0;
                }
            }
        if(s2[i]>='0'&&s2[i]<='9')
{
            b+=s2[i];
        }
        else
            {
                d=s2[i];
                if(s2[i]=='A'||s2[i]=='B'||s2[i]=='C')
                {
                    fb=1;
                }
                else
                {
                fb=0;
                }
            }
    }
    if(a==b&&c1==s1) cout<<"1";
    else cout<<"0";
    if(fa==fb&&a==b&&c1==s1) cout<<"1";
    else cout<<"0";
    bool f=1;
    if(c=='D'&&d=='C'||c=='c'&&d=='D') f=0;
    if((c+1==d||d+1==c)&&f&&c1==s1&&a==b&&fa==fb) cout<<"1";
    else cout<<"0";
    return 0;
}
