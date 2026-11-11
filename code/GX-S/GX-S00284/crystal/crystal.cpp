#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=2;i<=n;i++){
        int t=m;
        int maxn=1;
        for(int j=i-1;j>=1 && t>=a[i]-a[j];j--){
            t-=a[i]-a[j];
            maxn++;
        }
        if(maxn>ans){
            ans=maxn;
        }
    }
    cout<<ans;
    return 0;
}
