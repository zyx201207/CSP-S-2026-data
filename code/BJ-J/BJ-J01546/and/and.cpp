#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int a[N];
int x[N];
int x1[N];
signed main(){
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int max_a=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        x[i]=x[i-1]&a[i];
        max_a=max(max_a,a[i]);
    }
    for(int i=n;i>=1;i--){
        x1[i]=x1[i+1]&a[i];
    }
    if(m==1){
        cout<<max_a;
    }else if(m==2){
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }else if(m==n-1){
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,x[i-1]&x1[i+1]);
        }
        cout<<ans;
    }else{
        sort(a+1,a+n+1);
        int ans=0;
        for(int i=n;i>=n-m+1;i--){
            ans=ans&a[i];
        }
        cout<<ans;
    }
    return 0;
}
