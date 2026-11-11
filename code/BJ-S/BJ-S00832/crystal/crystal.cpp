#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,m;
int a[maxn],p[maxn];
int ans=1;
bool f1=0;
void check(int l,int r)
{
    if(ans>n-1) return;
    if(l<=m && m<r)
    {
        f1=1;
        cout<<ans;
        return ;
    }
    ans++;
    check(r,r+ans*p[ans]);
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    // if(n==1){
    //     cout<<1;
    //     return 0;
    // }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++)
    {
        p[i]=a[i+1]-a[i];
    }
    check(1,p[1]);
    if(!f1) cout<<n;
    cout<<endl;
    return 0;
}