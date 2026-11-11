#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int ans=-1;
    for(int i=0;i<n;i++)
    {
        if(i!=n-1)
        {
            if(a[i]==a[i+1])
            {
                continue;
            }
        }
        int tmp=1;
        int tm=m;
        for(int j=i-1;j>=0;j--)
        {
            if(tm>=a[i]-a[j])
            {
                tm-=(a[i]-a[j]);
                tmp++;
            }
            else
            {
                break;
            }
        }
        ans=max(ans,tmp);
    }
    cout<<ans;
    return 0;
}