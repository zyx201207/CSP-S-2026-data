#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int ans;
void dfs(int and1,int ch,int xb){
    if(ch>m)return;
    if(xb>n)return;
    if(ch==m){
        ans=max(ans,and1);
    }
    for(int i=xb;i<=n;i++){
        if(ch==0){
            dfs(a[i],ch+1,i+1);
        }else{
            dfs(and1&a[i],ch+1,i+1);
        }
        dfs(and1,ch,i+1);
    }
    return;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,0,1);
    cout<<ans;
    return 0;
}
