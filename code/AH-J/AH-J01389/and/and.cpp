#include<bits/stdc++.h>
using namespace std;
int n,m,mx;
int a[200005];
void dfs(int cnt,int an,int k){
    if(cnt==m){
        mx=max(mx,an);
        return;
    }
    for(int i=k;i<=n;i++){
        if(cnt==0){
            dfs(++cnt,a[i],++i);
        }else{
            dfs(++cnt,a[i]&an,++i);
        }
        cnt--;
        i--;
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    dfs(0,1,1);
    cout<<mx;
    return 0;
}
/*
freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int s=a[n],i=n,j=0;
    for(int i=n;i>=n-m+1;i--){
        s=s&a[i];
    }
    cout<<s;
*/
