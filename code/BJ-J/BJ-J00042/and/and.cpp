#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=2e5+5;
ull n,m,a[maxn],mxn=0,tmc;
int main()
{
    tmc=time(0);
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n,greater<int>());
    for(int i=0;i<n-m+1;i++)
    {
        ull x=a[i];
        for(int j=i;j<i+m;j++)x&=a[j];
        mxn=max(x,mxn);
        if(tmc-time(0)>900)
        {
            cout<<mxn;
            return 0;
        }
    }
    cout<<mxn;
    return 0;
}
