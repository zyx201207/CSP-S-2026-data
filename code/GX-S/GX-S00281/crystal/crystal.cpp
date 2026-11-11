#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
bool cmp(int x,int y){
    return x<y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int ans=1,an=1;
    for(int i=2;i<n;i++){
        int s=0;an=1;
        for(int j=i-1;j>=1;j--){
            if(s+a[i]-a[j]>m) break;
            s+=(a[i]-a[j]);
            an++;
        }
        ans=max(ans,an);
    }
    cout<<ans*2-1;
    return 0;
}
