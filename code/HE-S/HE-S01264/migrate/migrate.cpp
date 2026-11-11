#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int test,t,n,pre[2000010],ans;
LL d,a[2000010];
void solve1()
{
    int i,j;
    for(i=1; i<n; i++)

    return;
}
int main()
{
    int i,j;
    cin>>test>>t;
    while(t--)
    {
        cin>>n>>d;
        for(i=1; i<=n; i++) cin>>a[n];
        for(i=2; i<=n; i++)
        {
            pre[i]=pre[i-1];
            if(a[i]-a[i-1]>d) pre[i]++;
        }
        ans=0;
        solve1()
    }
    return 0;
}
