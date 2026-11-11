#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    vector<int> a(n+2);
    vector<char> c(n+2);
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    int l=1,r=n;
    while(l<r){
        int t=min(a[l],a[r]);
        a[l]-=t,a[r]-=t;
        if(c[l]!=c[r])ans+=t;
        if(!a[l])l++;
        if(!a[r])r--;
    }
    cout<<ans;
    return 0;
}
