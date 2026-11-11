#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[200005]={0};
    int b[200005]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        int s;
        for(int i=1;i<n;i++)
        {
            s=max(a[i],a[i+1]);
        }
        cout<<s;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n-m;i++)
        {
            b[i]+=a[i]&a[i+j];
        }
    }
    long long maxn=0;
    for(int i=1;i<n;i++)
    {
        maxn=max(b[i],b[i+1]);
    }
    cout<<maxn;
    return 0;
}