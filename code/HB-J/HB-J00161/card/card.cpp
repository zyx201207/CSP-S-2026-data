#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N];
int last[N];
bool vis[N];
int ans[N];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        last[a[i]]=i;
    }
    //for(int i=1;i<=m;i++){
    //    cout<<last[i]<<" ";
    //}
    for(int i=1;i<=n;i++){
        int j=i;
        while(j<=n){
            j=last[a[j]];
            ans[a[j]]++;
            j++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
