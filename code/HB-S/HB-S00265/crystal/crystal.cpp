#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll arr[1000005];
ll read()
{
    char ch=getchar();
    ll sign=1,inp=0;
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') sign=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        inp=inp*10+ch-'0';
        ch=getchar();
    }
    return inp*sign;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+n+1);
    ll sum=0;
    int l=1,ans=0;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]!=arr[i+1]||i==n)
        {
            while(sum>m) sum-=(arr[i]-arr[l]),++l;
            if(i!=n) sum+=(arr[i+1]-arr[i])*(i-l+1);
            ans=max(ans,i-l+1);
        }
    }
    cout<<ans;
    return 0;
}
/*
5 8
-3 -1 2 2 7
5 5
1 2 4 8 9
*/
