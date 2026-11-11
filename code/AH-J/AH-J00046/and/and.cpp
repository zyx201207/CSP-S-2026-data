#include<bits/stdc++.h>
using namespace std;
int n,m,t,ans;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    vector<int >v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n-m+1;i++)
    {
        int t=v[i];
        for(int j=i+1;j<i+m;j++)
        {
            t=t&v[j];

        }
        ans=max(ans,t);
    }
    cout<<ans;
    return 0;
}
