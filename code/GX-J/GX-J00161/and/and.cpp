#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y)
{
    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n;
    long long m;
    cin>>n;
    cin>>m;
    vector<long long> a(n+10);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a.begin(),a.end(),cmp);


    int ans=a[0];
    for(int i=1;i<m;i++)
        ans=ans&a[i];
    cout<<ans;
    return 0;
}
