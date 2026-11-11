#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[(int)1e6+5];
int ans=0;
vector <int> pa;
void p(){
    int x=a[pa[0]];
    for (int i=1;i<(int)pa.size();i++) x&=a[pa[i]];
    ans=max(ans,x);
    return;
}
void dfs(int k,int w){
    if (k==m){
        p();
        return;
    }
    for (int i=w;i<n;i++){
        pa.push_back(i);
        dfs(k+1,i+1);
        pa.pop_back();
    }
    return;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=0;i<n;i++) cin>>a[i];
    dfs(0,0);
    cout<<ans<<endl;
    return 0;
}
