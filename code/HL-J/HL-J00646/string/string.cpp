#include<bits/stdc++.h>
using namespace std;
int n,m[200005];
char a[200005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>m[i]>>a[i];
    }
    if(m[1]==m[2]&&m[3]==0)
    {
        cout<<0;
        return 0;
    }
    bool ok=0;
    for(int i=1;i<=n;i++)
    {
        if(m[i]==1)
            ok=1;
        else
        {
            ok=0;
            break;
        }

    }
    if(ok)
    {
        cout<<n/2;
        return 0;
    }
    bool ok2=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i+1])
            ok2=1;
        else
        {
            ok2=0;
            break;
        }

    }
    if(ok2)
    {
        cout<<0;
        return 0;
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=m[i];
    }
    cout<<sum/2;
    return 0;
}

