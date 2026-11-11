#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2005],maxx;
void dfs(int c,long long s,long long g){
    if(c==n+1){
        if(s!=4294967295&&g==0){
            maxx=max(maxx,s);
        }
        return;
    }
    dfs(c+1,s,g);
    if(g!=0){
        dfs(c+1,(s&a[c]),g-1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        dfs(1,4294967295,m);
        cout<<maxx;
    }else if(m==1){
        for(int i=1;i<=n;i++){
            maxx=max(maxx,a[i]);
        }
        cout<<maxx;
    }else if(m==n){
        maxx=4294967295;
        for(int i=1;i<=n;i++){
            maxx=maxx&a[i];
        }
        cout<<maxx;
    }else{
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxx=max(maxx,a[i]&a[j]);
            }
        }
        cout<<maxx;
    }
    return 0;
}
