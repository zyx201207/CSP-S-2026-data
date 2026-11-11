#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+100;
int n,m,sum,maxn;
int a[N];
void dfs(int x,int y){
    if(x>m){
        maxn=max(sum,maxn);
        return ;
    }
    if(y>n){
        return ;
    }
    for(int i=y;i<=n;i++){
        int s=sum;
        if(x==1){
            sum=a[i];
        }else{
            sum&=a[i];
        }
        dfs(x+1,i+1);
        if(x!=1){
            sum=s;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,1);
    cout<<maxn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
