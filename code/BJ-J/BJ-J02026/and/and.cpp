#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010][2],t=0,s=0,b[200010];
void dfs(int x,int y){
    if(x>m){
        for(int j=2;j<=m;j++){
            s=b[j]&b[j-1];
            b[j]=s;
        }
        t=max(t,b[m]);
        return;
    }
    for(int i=y;i<=n;i++){
        b[x]=a[i][0];
        dfs(x+1,i+1);
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    std::cin>>n>>m;
    for(int i=1;i<=n;i++){
        std::cin>>a[i][0];
    }
    dfs(1,1);
    std::cout<<t;
    fclose(stdin);
    fclose(stdout);
    return 0;
}