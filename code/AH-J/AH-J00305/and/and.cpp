#include<bits/stdc++.h>
using namespace std;
int n,a[200005],m,maxa,mx1,mx2,ps;
void dfs(int x,int ans,int y,bool f){
    if(x==n){
        if(y==m){
            maxa=max(maxa,ans);
        }
        return ;
    }
    dfs(x+1,ans,y,f);
    if(!f){
        dfs(x+1,a[x],y+1,true);
    }else{
        dfs(x+1,ans&a[x],y+1,f);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(mx1<a[i]){
            ps=i;
            mx1=a[i];
        }
        if(mx2<a[i]&&ps!=i){
            mx2=a[i];
        }
    }
    if(n<=20){
        dfs(1,0,0,false);
        cout<<maxa;
    }else{
        cout<<(mx1&mx2);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
