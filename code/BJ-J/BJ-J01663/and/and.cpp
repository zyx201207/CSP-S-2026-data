#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans=0;
bool vis[N];
void qpl(int num,int k){
    if(k==m){
        ans=max(ans,num);
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])  continue;
        vis[i]=1;
        qpl((num&a[i]),k+1);
        vis[i]=0;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        vis[i]=1;
        qpl(a[i],1);
        vis[i]=0;
    }
    cout<<ans;
    return 0;
}
