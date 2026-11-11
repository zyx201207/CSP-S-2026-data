#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,M=3e5+10;;
int n,m;
int a[N];
int num[M],nxt[M];
vector<int> v[M];
void dfs(int x){
    for(auto y:v[x]){
        dfs(y);
        num[x]+=num[y];
    }
    return;
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        num[a[i]]++;
        nxt[a[i]]=a[i+1];
    }
    for(int i=1;i<=m;i++){
        v[nxt[i]].push_back(i);
    }
    dfs(a[n]);
    for(int i=1;i<=m;i++)cout<<num[i]<<" ";
    return 0;
}