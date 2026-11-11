#include<bits/stdc++.h>
using namespace std;

long long p[32]={1};

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<long long> a(n,0);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n/2;i++)
    {
        swap(a[i],a[n-i-1]);
    }
    long long ans=a[0];
    for(int i=1;i<m;i++)
    {
        ans=ans&a[i];
    }
    cout<<ans;
    return 0;
}
