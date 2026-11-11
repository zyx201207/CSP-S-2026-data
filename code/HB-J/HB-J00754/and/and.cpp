#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
bool cmp(int a,int b){return a>b;}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,cmp);
    int ans=a[1];
    for(int i=2;i<=m;i++) ans=(ans&a[i]);
    cout<<ans;
    return 0;
}
