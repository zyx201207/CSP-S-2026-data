#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#define int long long
using namespace std;
int n,m,used,l=1,r=1,ans;
int a[500005],b[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        b[i]=a[i]-a[i-1];
    }
    while(r<=n){
        while(used+(r-l+1)*b[r]<=m&&r<=n)used+=(r-l+1)*b[r],r++;
        ans=max(ans,r-l+1);
        used-=a[r-1]-a[l];
        l++;
    }cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
