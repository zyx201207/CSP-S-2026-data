#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
int n;
ll m;
ll a[N],presum[N];
//to check if the cost is available
bool check(int i,int j)
{
    ll need_sum=a[i]*(i-j+1);
    ll cost=need_sum-(presum[i]-presum[j-1]);
    return cost<=m;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];

    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)presum[i]=presum[i-1]+a[i];

    int j=1;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        //use a[i] as the standard to calculate how much need to be costed
        while(j<=i && !check(i,j))j++;
        ans=max(ans,(i-j+1));
    }
    cout<<ans<<endl;
    return 0;
}
/*
cd crystal
ulimit -s unlimited
g++ crystal.cpp -o crystal -O2 -std=c++14 -static -Wall
time ./crystal < crystal.in
*/