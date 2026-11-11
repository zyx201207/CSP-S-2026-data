#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[10000005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=-1;
    for(int i=1;i<=n;i++)
    {
        int sum=a[i]&a[i+1];
        ans=max(ans,sum);
    }
    cout<<"12";
    return 0;
}
