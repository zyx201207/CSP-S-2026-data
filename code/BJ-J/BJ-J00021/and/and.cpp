#include <bits/stdc++.h>
using namespace std;
long long a[200005];int maxans,m,n,maxans2,maxans3,wa,wb,wc,wd;
int dfs(int shu,int u,int o){

    if(o==m){

            maxans=max(maxans,shu);
            return 0;
    }
    if(u==n)return 0;
    if(shu==0){
        shu=a[u];
        dfs(0,u+1,o);
        dfs(shu,u+1,o+1);
    }
    else{
        dfs(shu,u+1,o);
        dfs(shu&a[u],u+1,o+1);
    }


}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>=4)wd=1;
        if(a[i]==3)wa=1;
        if(a[i]==2)wb=1;
        if(a[i]==1)wc=1;
        //maxans2>a[i]?maxans2:a[i]
        maxans2=maxans2>a[i]?maxans2:a[i];
        if(i==1)maxans3=a[i];
        else maxans3=a[i]&maxans3;
    }
    if(n<=20){
        dfs(0,1,0);
        cout<<maxans;
    }
    else if(m==1 || m==n){
        if(m==1)cout<<maxans2;
        else if(m==n)cout<<maxans3;
    }
    else{
        if(wd==0){
            if(wa==1)cout<<3;
            else if(wb==1 && wc==1)cout<<3;
            else if(wb==1)cout<<2;
            else cout<<1;
        }

    }

    return 0;
}