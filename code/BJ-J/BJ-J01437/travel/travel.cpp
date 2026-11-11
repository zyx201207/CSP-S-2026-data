#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int a=0,b=0,c=0,d=0;
    if(c1==c2)
        a=1;
    string ss1,ss2;
    ss1=s1[0];
    ss1+=s1[1];
    ss2=s2[0];
    ss2+=s2[1];
    if(a==1&&ss1==ss2)
        b=1;
    if(b==1&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')))
        c=1;
    if(c==1&&abs(s1[2]-s2[2])==1)
        d=1;
    cout<<a<<b<<c<<d<<endl;
    return 0;
}
