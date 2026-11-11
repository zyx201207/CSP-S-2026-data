#include<bits/stdc++.h>
using namespace std;
int a[500005],cnt[300005],n,m;
bool vis[300005];
void baoli(){
    for(int i=1;i<=n;i++){
        stack<int> stk;
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                while(!stk.empty()){
                    if(stk.top()==a[j]) break;
                    vis[stk.top()]=0;
                    stk.pop();
                }
            }else{
                vis[a[j]]=1;
                stk.push(a[j]);
            }
        }
        while(!stk.empty()){
            cnt[stk.top()]++;
            stk.pop();
        }
        for(int j=1;j<=m;j++) vis[j]=0;
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
}
void special_a(){
    for(int i=1;i<=n;i++){
        cnt[a[i]]=i;
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    bool flag=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]) flag=0;
    }
    if(flag) special_a();
    else baoli();
    return 0;
}
