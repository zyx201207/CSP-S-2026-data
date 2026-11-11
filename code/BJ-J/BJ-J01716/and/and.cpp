#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[2004];
int b[2003];
void dfs(int d,int x){
    if(d==m){
        int an=b[0];
        for(int i=1;i<d;i++){
            an=an&b[i];
        }
        ans=max(an,ans);
        cout<<ans;
        return;
    }
    b[d]=a[x];
    for(int i=x;i<n;i++){
        dfs(d+1,i);
    }
    b[d]=0;
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(n>2000) return 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        dfs(0,i);
    }

    cout<<ans;
}
