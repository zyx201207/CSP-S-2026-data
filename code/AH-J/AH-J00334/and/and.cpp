#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
int n,m,a[MAXN];
int ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n,greater<int>());
    ans=a[0];
    for (int i=1;i<m;i++)
        ans=ans&a[i];
    cout<<ans<<endl;
    return 0;
}
