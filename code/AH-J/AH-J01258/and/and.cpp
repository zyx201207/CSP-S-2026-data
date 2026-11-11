#include<bits/stdc++.h>
using namespace std;
//using ll=long long;
int n,m,ans;
int a[200010];
map<int,int> mp;
bool cmp(int x,int y){
    return x>y;
}
void dfs(int i,int h,int cnt){
    if(cnt==m){
        ans=max(ans,h);
        return;
    }
    if(i>=n||ans&h==ans)return;
    if(mp[h&a[i]]<cnt+1){
        mp[h&a[i]]=cnt+1;
        dfs(i+1,h&a[i],cnt+1);
    }
    dfs(i+1,h,cnt);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    dfs(1,2147483647,0);
    cout<<ans;
    return 0;
}

