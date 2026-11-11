#include<bits/stdc++.h>
using namespace std;
long long a[10000005];
bool cmp(int x,int y)
{
    return x>=y;
}
int main()
{
    freopen("add.in","r",stdin);
    freopen("add.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    int t=a[m];
    cout<<t;
    return 0;
}
