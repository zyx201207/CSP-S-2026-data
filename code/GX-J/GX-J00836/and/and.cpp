#include <bits/stdc++.h>
using namespace std;
const int N=1e5*2+10;
int a[N];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    long long mx=0;
    for(int i=1;i+m-1<=n;i++)
    {
        long long num=a[i];
        for(int j=1;j<m;j++)
        {
            num=(num&a[i+j]);
        }
        mx=max(mx,num);
    }
    cout<<mx;
    return 0;
}
