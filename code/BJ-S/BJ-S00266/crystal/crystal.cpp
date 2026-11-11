#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N=500005;
int n;long long m;long long a[N]={0};long long s[N]={0};priority_queue<int> pq;long long qz[N]={0};
int px[N]={0};
long long calc(int x,int y)
{
    if(x==y) return 0;
    long long mi=s[y];
    long long all=y-x+1;
    mi*=all;
    long long sum=qz[x]-qz[y+1];
    return sum-mi;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;int tot=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];tot+=a[i];
    }
    long long d=abs(a[2]-a[1]);long long cnt=0;
    for(int i=1;i<=n;i++)
    {
        cnt+=d*i;
        if(cnt>m)
        {
            cout << i;
            return 0;
        }
    }
    // int maxans=-1;
    // for(int i=1;i<=n;i++)
    // {
    //     if(a[i]<maxans) continue;
    //     int minc=INT_MAX;int cnt=tot-m;int act=n;
    //     for(int j=1;j<=n;j++)
    //     {
    //         if(minc>a[i]-a[j])
    //     }
    // }
    return 0;
}