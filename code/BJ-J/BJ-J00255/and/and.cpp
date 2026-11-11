#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200100];
int ans=0;
map<int,int> mp;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],mp[a[i]]++;
    sort(a+1,a+n+1,greater<int>());/*
    int pos;
    int maxs=-1;
    for(int i=1;i<=n;i++){
        if(max(maxs,mp[i])==mp[i]){
            ans=mp[i];
            pos=i;
            break;
        }
    }
    if(maxs==-1)pos=1;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(i==pos||a[i]==a[pos])continue;
        if(max(ans,ans&a[i])==ans&a[i]){
            cnt++;
            ans&=a[i];
            if(cnt==m)break;
        }
    }
    cout<<ans;可惜了dp不对这贪心还过不了服了*/
    ans=a[1];
    for(int i=2;i<=m;i++)ans&=a[i];
    cout<<ans;
    return 0;
}
