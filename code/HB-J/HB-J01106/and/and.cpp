#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin>>n>>m;
    long long ans=0;
    vector<long long> a(n-1);
    vector<long long> xuanze(m);
    long long q=1
    for(int i=0;i++;i<=n)
    {
        cin>>a[i];
        ans=max(ans,a[i]);
    }
    if(m==1) cout<<ans;
    ans=0;
    if(m=n)
    {
        for(int i=0;i<n;i++)
        {
            ans=a[i] and a[i+1];
        }
        cout<<ans;
    }

    return 0;
}
