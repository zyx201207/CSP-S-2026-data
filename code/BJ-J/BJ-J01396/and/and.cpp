#include<bits/stdc++.h>
using namespace std;
int n,m,maxx,maxn,s[100005];
int a[100005];


int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxx=max(maxx,a[i]);
        if(i>=2)s[i]=s[i-1]&a[i];
        else s[i]=a[i];
    }
    if(m==1)
    {
        cout<<maxx;
        return 0;
    }
    if(m==n)
    {
        cout<<s[n];
        return 0;
    }

    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
        {
            maxn=max(maxn,(a[i]&a[j]));
        }
    cout<<maxn;
    return 0;
}