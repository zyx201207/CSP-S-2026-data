#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{

    freopen("crystal.in","r",stdin);
    
    freopen("crystal.out","w",stdout);
    long long a[1000006];
    long long n,m,opr,rm;
    long long c=1,maxc=1;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        opr=i+1;
        c=1;
        rm=m;
        while(rm>=a[i]-a[opr]&&opr<=n)
        {
            rm-=a[i]-a[opr];
            opr++;
            c++;
        }
        if(c>maxc) maxc=c;
        
    }
    cout<<maxc;
    return 0;
}
