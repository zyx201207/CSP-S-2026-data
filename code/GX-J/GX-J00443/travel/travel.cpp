#include<bits/stdc++.h>
using namespace std;
int a=0,b=0,c=0,d=0,r[10]={0},g[10]={0},f=0,t=0;
int main ()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,w;
    string cnt,ans;
    cin>>n>>cnt>>w>>ans;
    if(n==w)
    {
        a=1;
    }
    else
    {
        a=0;
    }
    char p=cnt[2],q=ans[2];
    for(int i=0;i<cnt.size()-1;i++)
    {
        g[i]=cnt[i];
        r[i]=ans[i];
        if(g[i]==r[i])
        {
            b=1;
        }
        else
        {
            b=0;
            break;
        }
    }
    if(p>='A'&&p<='C')
    {
        t++;
    }
    else
    {
        f++;
    }
    if(q>='A'&&q<='C')
    {
        t++;
    }
    else
    {
        f++;
    }
    if(a==0)
    {
        b=0;
    }
    cout<<a<<b;
    if(t==2||f==2)
    {
        if(b!=0)
        {
            c=1;
        }
    }
    else
    {
        c=0;
    }
    if(int(q)+1==int(p)||int(q)-1==int(p))
    {
        if(c!=0)
        {
            d=1;
        }
    }
    else
    {
        d=0;
    }
    cout<<c<<d;
    return 0;
}
