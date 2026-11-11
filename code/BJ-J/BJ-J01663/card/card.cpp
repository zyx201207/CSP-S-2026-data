#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[M],vis[M],pd[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(vis[a[i]]!=0)    pd[vis[a[i]]]=i;
        vis[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(pd[j]!=0){
                j=pd[j]-1;
            }else{
                ans[a[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
