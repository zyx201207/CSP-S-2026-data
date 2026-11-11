#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001];
stack<int> s[300001];
int fa[500001];
int ans[300001];
int find(int x){
    // cout<<x<<'\n';
    if(x==fa[x]){
        // cout<<"OK "<<x<<'\n';
        return x;
    }
    return fa[x]=find(fa[x]);
}
void solve(){
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i+1]){
            ans[a[i]]=i;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return ;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    bool flag=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1 && a[i]<a[i-1]){
            flag=0;
        }
    }
    if(flag){
        solve();
        return 0;
    }
    for(int t=1;t<=n;t++){
        iota(fa+1,fa+n+2,1);
        for(int i=1;i<=m;i++){
            while(!s[i].empty()){
                s[i].pop();
            }
        }
        for(int i=t;i<=n;i++){
            if(!s[a[i]].empty()){
                int x=s[a[i]].top();
                for(int j=find(x);j<i;j=find(j+1)){
                    // cout<<j<<'\n';
                    // cout<<s[a[j]].size()<<'\n';
                    s[a[j]].pop();
                    fa[j]=j+1;
                }
                s[a[i]].push(i);
            }else{
                s[a[i]].push(i);
            }
        }
        for(int i=find(t);i<=n;i=find(i+1)){
            ans[a[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}