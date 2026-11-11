#include <bits/stdc++.h>
using namespace std;
long long a[500010];
int main()
{   freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    long long m;
    cin>>n>>m;
    long long ans=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long y,x;
    for(int i=1;i<=n;i++){
        y=0,x=1;
        for(int j=i-1;j>=1;j--){
            y+=a[i]-a[j];
            if(y<=m) x++;
            else break;
        }
        ans=max(ans,x);
    }
    cout<<ans;
    return 0;
}
