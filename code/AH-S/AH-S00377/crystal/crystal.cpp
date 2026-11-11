#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005]={0},s[500005]={0};
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        int t=i,b=a[i]-a[i-1];
        s[i]=s[i-1]+b*(t-1);
    }
    for(int i=n;i>=1;i--)
    {
        int t=i;
        if(m>=s[i])
        {
            cout<<t;
            return 0;
        }
    }
    return 0;
}
