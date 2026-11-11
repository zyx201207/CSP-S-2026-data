#include<bits/stdc++.h>
using namespace std;
struct str
{
    unsigned long long a,b;
    char c;
};
str m[200010];
int v[30];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x,m1=0,ans=0,f=1;
    unsigned long long n1=0;
    char y;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        if(v[y-'a']==0&&i!=0)
        {
            f=0;
        }
        v[y-'a']=1;
        if(m[m1].c==y)
        {
            m[m1].b+=x;
        }
        else
        {
            m1++;
            m[m1].a=n1;
            m[m1].b=n1+x-1;
            m[m1].c=y;
        }
        n1+=x;
    }
    if(f)
    {
        cout<<0;
        return 0;
    }
    for(unsigned long long i=0;i<=((n1+1)/2)-1;i++)
    {
        char p,q;
        for(int j=1;j<=m1;j++)
        {
            if(m[j].b>=i)            {
                p=m[j].c;
                break;
            }
        }
        for(int j=m1;j>=1;j--)
        {
            if(m[j].a<=n1-i-1)
            {
                q=m[j].c;
                break;
            }
        }
        if(p!=q)
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
