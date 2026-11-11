#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001];
long long ans=-0x3f3f3f3f;
long long cnt;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cnt=a[i];
        for(int j=i+1;j<=m;j++){
            cnt=cnt^a[j];
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}