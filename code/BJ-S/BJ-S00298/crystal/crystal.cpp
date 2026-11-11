#include<bits/stdc++.h>
using namespace std;
int n,ans=1;
long long m;
int a[500005];
bool vis[500005]={0};
map<int,int> cnt;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
        ans=max(ans,cnt[a[i]]);
    }
    sort(a+1,a+n+1);
    int xans=0,mx=m;
    for(int i=n;i>=1;i--){
        if(a[n]-a[i]<=mx) mx-=(a[n]-a[i]),xans++;
        else break;
    }
    ans=max(xans,ans);
    for(int i=n-1;i>=1;i--){
        if(a[i]==a[i+1]) continue;
        int cur=a[i+1]-a[i];
        xans-=cnt[a[i+1]];
        mx+=(cur*xans);
        for(int j=i-xans;j>=1;j--){
            if(a[i]-a[j]<=mx) mx-=(a[i]-a[j]),xans++;
            else break;
        }
        ans=max(xans,ans);
    }
   /* for(int i=1;i<=n;i++){
        if(vis[a[i]]) continue;
        int mx=0,xans=cnt[a[i]];
        vis[a[i]]=1;
        for(int j=i-1;j>=1;j--){
            int cur=a[i]-a[j];
            if(mx+cur<=m){
                mx+=cur;
                xans++;
            }else{
                break;
            }
        }
        ans=max(ans,xans);
    }*/

    cout<<ans;
    return 0;
}
