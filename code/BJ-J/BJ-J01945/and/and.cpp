#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],b[N],ans;
void A(int u,int sum,int ans1){
    if(sum==m){
        if(ans1>ans)ans=ans1;
        return;
    }
    if(u>n)return;
    A(u+1,sum,ans1);
    if(ans1==0){
        ans1=a[u];
        A(u+1,sum+1,ans1);
    }
    else{
        A(u+1,sum+1,ans1&a[u]);
    }
    return;
}
signed main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
if(n<=2000){
    A(1,0,0);
    cout<<ans;
}
return 0;
}
