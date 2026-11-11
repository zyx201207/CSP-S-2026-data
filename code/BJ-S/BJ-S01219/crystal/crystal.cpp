#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,k,a[500009],maxn=0,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        k=m,ans=0;
        for(int j=1;j<i;j++){
            k-=a[i]-a[j];
            ans++;
            if(k<0)  break;
        }
        maxn=max(maxn,ans+1);
    }
    cout<<maxn;
    return 0;
}
