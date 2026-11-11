#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==m)
    {
        long long ans=0;
        for(int i=1;i<=n;i++)
            ans=ans&a[i];
        cout<<ans;
    }
    else if(m==2)
    {
        long long maxn=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
                maxn=max(maxn,a[i]&a[j]);
        }
        cout<<maxn;
    }
    else if(m==1)
    {
        long long maxn=0;
        for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
        cout<<maxn;
    }
    return 0;
}
