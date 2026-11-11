#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],ans[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans[i]=ans[i-1]+a[i];
    }
    int ans1=1;
    for(int i=1;i<=n;i++){
        if(m>=ans[i]){
            ans1=max(ans1,i);
        }
    }
    cout<<ans1+1<<endl;
    return 0;
}
