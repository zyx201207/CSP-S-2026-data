#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f1=1,f2=1,f3=1,f4=1,a1,a2;
string s1,s2,s3,s4,s;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    for(ll i=0;i<s1.size();i++)
        if(s1[i]!=s3[i]) f1=0;
    if(f1==1)
    {
        for(ll i=0;i<2;i++)
            if(s2[i]!=s4[i]) f2=0;
        if(f2==1)
        {
            char c1=s2[2],c2=s4[2];
            if(c1>='A'&&c1<='C') a1=1;
            else a1=2;
            if(c2>='A'&&c2<='C') a2=1;
            else a2=2;
            if(a1!=a2) f3=0,f4=0;
            else
            {
                ll k1=c1-'A',k2=c2-'A';
                if(a1==1)
                {
                    if(abs(k1-k2)!=1) f4=0;
                }
                else
                {
                    if(abs(k1-k2)!=2) f4=0;
                }
            }
        }
        else f3=0,f4=0;
    }
    else f2=0,f3=0,f4=0;
    cout<<f1<<f2<<f3<<f4;
    return 0;
}
