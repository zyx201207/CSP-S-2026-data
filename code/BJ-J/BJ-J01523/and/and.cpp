#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool cmp(int a,int b){
    return a>b;
}
int big,now = pow(2,20)-1;
void dfs(int depth,int ind){
    if(depth>m){
        big = max(big,now);
        return ;
    }
    for(int i = ind;i<=n;i++){
        int temp = now;
        now = now&a[i];
        dfs(depth+1,i+1);
        now = temp;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i = 1;i<=n;i++) cin>>a[i];
    if(m==n){
        int ans = a[1];
        for(int i = 2;i<=n;i++) ans = ans&a[i];
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1,cmp);

    if(m==1){
        cout<<a[1];
        return 0;
    }if(n<=20){
        dfs(1,1);
        cout<<big;
        return 0;
    }
    if(m==2){
        int ans = a[1]&a[2];
        cout<<ans;
        return 0;
    }
//qiuqiunigeiwodianfenba

    return 0;
}
