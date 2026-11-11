#include<bits/stdc++.h>
using namespace std;
struct subs
{
    long long a;
    char c;
}x[200001],y[200001];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i].a>>x[i].c;
        if(x[i].c==x[i-1].c)
        {
            x[i-1].a+=x[i].a;
            i--;
            n--;
        }
    }
    for(int i=1;i<=n;i++)
    {
        y[n-i+1]=x[i];
    }
    int f=1,s=1;
    for(;f<=n&&s<=n;)
    {
        if(y[s].a==x[f].a)
        {
            if(x[f].c!=y[s].c)ans+=x[f].a;

            f++,s++;
        }
        else if(y[s].a<x[f].a)
        {
            if(x[f].c!=y[s].c)ans+=y[s].a;
            x[f].a-=y[s].a;
            s++;
        }
        else
        {
            if(x[f].c!=y[s].c)ans+=x[f].a;
            y[s].a-=x[f].a;
            f++;
        }
    }
    cout<<ans/2;
    return 0;
}
