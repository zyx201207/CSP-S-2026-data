#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
vector<int> g[M];
int a[N],ans[M];
void dg(int l,int r){
    int fj=a[l];
    ans[fj]+=r-l+1;
    int st=lower_bound(g[fj].begin(),g[fj].end(),l)-g[fj].begin();
    int i=0;
    for(i=st;i+1<g[fj].size()&&g[fj][i+1]<=r;i++){
        if(g[fj][i]==g[fj][i+1]-1){
            continue;
        }
        dg(g[fj][i]+1,g[fj][i+1]-1);
    }
    if(g[fj][i]<r){
        dg(g[fj][i]+1,r);
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[n-i+1];
    }
    for(int i=1;i<=n;i++){
        g[a[i]].push_back(i);
    }
    dg(1,n);
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
