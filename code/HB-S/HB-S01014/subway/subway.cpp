#include<bits/stdc++.h>
using namespace std;
int t=0,x,y;
int c,n,m,d,q;
int a1[505],a2[505],t1[505],t2[505],g;
int aaa(int a,int b)
{
    if(a==b)
        return t;
    else
    {
        for(int i=0;i<n;i++)
            if(a2[i]==b)
        {
            t+=t2[i]+t1[i];
            return aaa(a,i);
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    int w[m];
    for(int i=0;i<m;i++)
        cin>>w[i];
    for(int i=0;i<n;i++)
    {
        cin>>g;
        if(g==1)
        {
            cin>>a1[i]>>t1[i];
            a2[i]=0;
            t2[i]=0;
        }
        else if(g==0)
        {
            a2[i]=0;
            t2[i]=0;
            a1[i]=0;
            t1[i]=0;
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y;
        t=w[x]+w[y];
        cout<<aaa(x,y)<<endl;
    }
}
