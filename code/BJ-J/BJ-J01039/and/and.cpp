#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int n,m,a[200005],vis[200005],maxx=-1;
void dfs(int c,int z){
    if(c==m){
        //cout<<z<<' ';
        maxx=max(maxx,z);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            int ls1=z;
            vis[i]=1;
            dfs(c+1,ls1&=a[i]);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    if(m==1){
        cout<<maxx;
        return 0;
    }else if(m==2){
        maxx=-1;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                int ls1=a[i],ls2=a[j];
                ls1&=ls2;
                maxx=max(maxx,ls1);
            }
        }
        cout<<maxx;
        return 0;
    }else if(m==n){
        for(int i=2;i<=n;i++){
            a[1]&=a[i];
        }
        cout<<a[1];
    }else if(n<=20){
        maxx=-1;
        dfs(0,a[1]);
        cout<<maxx;
    }else {
        sort(a+1,a+n,cmp);
        cout<<a[m];
    }
    return 0;
}
