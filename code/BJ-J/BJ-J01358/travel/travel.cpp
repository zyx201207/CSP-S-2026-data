#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string k1,k2;
    for(int i=0;i<2;i++)
    {
        k1+=s1[i];
        k2+=s2[i];
    }
    char h1=s1[2],h2=s2[2];
    //cout<<c1<<s1<<c2<<s2<<" "<<k1<<" "<<k2<<" "<<h1<<" "<<h2;
    if(c1!=c2)
    {
        cout<<0000;
        return 0;
    }

    else cout<<1;
    if(k1!=k2)
    {
        cout<<000;
        return 0;
    }
    else cout<<1;
    if(!((h1>'C' and h2>'C') or (h1<='C' and h2<='C')))
    {
        cout<<00;
        return 0;
    }
    else cout<<1;
    if(abs(h1-h2)==1)
        cout<<1;
    else cout<<0;
    return 0;
}
