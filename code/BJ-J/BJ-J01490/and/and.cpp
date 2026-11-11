#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,m,a[N],mx;
void dfs(int x,int now,int cho){
    if(x>n||cho>m){
        if(cho>m) mx=max(mx,now);
        return ;
    }
    dfs(x+1,now&a[x],cho+1);
    dfs(x+1,now,cho);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 1;i<=n;i++){
        dfs(i,a[i],1);
    }
    cout << mx;
    return 0;
}