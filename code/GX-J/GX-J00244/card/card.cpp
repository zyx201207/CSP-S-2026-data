#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],ans[300010];
bool b[500010];
stack<int> q;
bool f=1;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]) f=0;
    }
    if(f){
        for(int i=1;i<=n;i++) ans[a[i]]=i;
        for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
        return 0;
    }
    for(int i=1;i<=n;i++){
        memset(b,0,sizeof b);
        for(int j=i;j<=n;j++){
            while(b[a[j]]){
                b[q.top()]=0;
                q.pop();
            }
            q.push(a[j]);b[a[j]]=1;
        }
        while(!q.empty()){
            ans[q.top()]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
