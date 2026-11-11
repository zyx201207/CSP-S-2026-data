#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[1000005];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long sum=0;
    int l=1,r=n;
    while(m--)
    {
        sum+=a[l]&a[r];
        l++;
        r--;
    }
    cout<<sum;
    return 0;
}
