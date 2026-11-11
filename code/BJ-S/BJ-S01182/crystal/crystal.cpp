#include<bits/stdc++.h>
using namespace std;
long long a[500002];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m,maxn=0,hao=0,l=1,yi=1;//l是指针（[l,i]均可）  hao:当前的总耗费（之前都已经变为a[i-1]了）
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++)//枚举最终变为的数
    {
        hao+=(i-l)*(a[i]-a[i-1]);//不包含i（之前都已经变为a[i-1]了）
        while(l+1<=i-1&&hao>m)
        {
            hao-=(a[i]-a[l]);
            l++;
        }
        if(hao>m)//还是不行
        {
            hao=0;
            l=i;
            maxn=max(maxn,yi);
        }
        else
            maxn=max(maxn,i-l+1);
    }
    cout<<maxn;
    return 0;
}