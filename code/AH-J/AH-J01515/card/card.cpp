#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[500005],ans[500005],cnt[500005];
bool vis[500005];
stack<int> s;
void clean(){
    for(int i=1;i<=n;i++){
        vis[i]=0;
    }
}
void solve(int t){
    for(int i=t;i<=n;i++){
        if(vis[a[i]]){
            while(!s.empty()&&s.top()!=a[i]){
                vis[s.top()]=false;
                s.pop();
            }
        }else{
            s.push(a[i]);
        }
        vis[a[i]]=true;
    }
    while(!s.empty()){
        ans[s.top()]++;
        s.pop();
    }
}
bool check(){
    for(int i=1;i<n;i++){
        if(a[i]>a[i+1]){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(check()){
        for(int i=1;i<=n;i++){
            cnt[a[i]]++;
        }
        for(int i=1;i<=m;i++){
            ans[i]=ans[i-1]+cnt[i];
            cout<<ans[i]<<" ";
        }
        return 0;
    }
    for(int k=1;k<=n;k++){
        clean();
        solve(k);
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
