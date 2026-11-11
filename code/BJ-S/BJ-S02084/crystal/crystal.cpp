#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> v(n+1,0);
    vector<int> s(n+1,0);
    for(int i=1;i<=n;i++) scanf("%lld",&v[i]);
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++) s[i]=s[i-1]+v[i];
    int ans=1;
    for(int i=2;i<=n;i++){
        int sum=i*v[i]-s[i];
        if(sum<=m) ans=i;
        else if(sum>m) break;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
