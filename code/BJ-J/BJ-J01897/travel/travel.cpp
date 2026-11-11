#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    bool ans1=0,ans2=0,ans3=0,ans4=0;
    if(a==c)ans1=1;
    else ans1=0;
    string s=b.substr(0,2),t=d.substr(0,2);
    if(ans1==1&&s==t)ans2=1;
    else ans2=0;
    if(ans2==1)
    {
        char x=b[2],y=d[2];
        if(x>='A'&&x<='C'&&y>='A'&&y<='C'&&x!=y)
        {
            ans3=1;
        }else{
            if(x>='D'&&x<='F'&&y>='D'&&y<='F'&&x!=y)
            {
                ans3=1;
            }
        }
    }else ans3=0;
    if(ans3==1)
    {
        char x=b[2],y=d[2];
        if(x=='A'&&y=='B')
        {
            ans4=1;
        }else if(x=='B'&&y=='A')
        {
            ans4=1;
        }else if(x=='B'&&y=='C')
        {
            ans4=1;
        }else if(x=='C'&&y=='B')
        {
            ans4=1;
        }else if(x=='D'&&y=='F')
        {
            ans4=1;
        }else if(x=='F'&&y=='D')
        {
            ans4=1;
        }else ans4=0;
    }
    cout<<ans1<<ans2<<ans3<<ans4;
    return 0;
}
