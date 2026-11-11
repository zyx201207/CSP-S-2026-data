#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[500005],num;
priority_queue<long long>q;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    ans=n;
    for(int i=1;i<=n;i=i+1)
    {
        cin>>a[i];
        q.push(a[i]);
    }
    sort(a+1,a+n+1);
    while(!q.empty())
    {
        num=0;
        for(int i=1;i<=n;i=i+1)
        {
            num=num+q.top()-a[i];
        }
        if(num<=m)
        {
            break;
        }
        else
        {
            ans--;
            q.pop();
        }
        n--;
    }
    cout<<ans;
    return 0;
}