#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long ans=1;
queue<long long>q;
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
    for(int i=1;i<=n;i++)
    {
        q.push(a[i]);
        m-=(q.size()-1)*(a[i]-a[i-1]);
        while(m<0)
        {
            long long x=q.front();
            q.pop();
            m+=a[i]-x;
        }
        ans=max(ans,(long long)q.size());
    }
    cout<<ans;
    return 0;
}
