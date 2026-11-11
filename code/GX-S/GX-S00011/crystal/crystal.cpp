#include<bits/stdc++.h>
using namespace std;
int a[10000010],tmp=INT_MAX,n,m,stad,ps,ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    stad=(a[1]+a[n])/2;
    for(int i=1;i<=n;i++)
    {
        if(abs(stad-a[i])<tmp)
        {
        tmp=stad-a[i];
        ps=i;
        }
    }
    while(m)
    {
        a[ps-1]++;
        if(a[ps-1]==a[ps])
        {
            ps--;
            ans++;
        }
        m--;
    }
    cout<<ans;
    return 0;
}
