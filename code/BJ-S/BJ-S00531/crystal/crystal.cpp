#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int ai;
        cin>>ai;
        if(ai<0)
            ai*=-1;
        a[i]=ai;
    }
    int i=1;
    while(m>0&&i<=n)
    {
        sort(a+1,a+n+1);
        m-=a[i];
        a[i]*=2;
        i++;
        ans++;
    }
    cout<<ans;
    return 0;
}