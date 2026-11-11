#include<bits/stdc++.h>
using namespace std;
const int N=2e5 + 7;
int n,m,a[N];
long long ans=0;
void DFS(int x,int l,long long ad){
    if(x>m){
        ans=max(ans,ad);
        return;
    }
    for(int i=l+1;i<=n-m+x;++i){
        DFS(x+1,i,ad&a[i]);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    DFS(1,0,2147483647);
    cout<<ans;
    return 0;
}
