#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
bool check(int x){
    int sum=0;
    for(int i=x-1;i>=1;i--) sum+=(a[x]-a[i]);
    return (sum<=m);
}
int get(int x){
    int sum=0,cnt=1;
    for(int i=x-1;i>=1;i--){
        sum+=(a[x]-a[i]);
        if(sum>m) break;
        else cnt++;
    }
    return cnt;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    bool A=1,B=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        A=A&&a[i]==i;
        if(i==1) continue;
        int d=a[2]-a[1];
        B=B&&a[i]-a[i-1]==d;
    }
    if(A) cout<<get(n);
    else if(B) cout<<get(n);
    else{
        int ans=-1;
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++) ans=max(ans,get(i));
        cout<<ans;
    }
    return 0;
}
