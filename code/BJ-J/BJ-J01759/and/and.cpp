#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,mx;
int a[200000+10];
void dfs(int deep,int num,int ans){
    if(ans<=mx)return;
    if(num==m){
        mx=max(mx,ans);
        return;
    }
    if(deep==n+2-m+num)return;
    dfs(deep+1,num,ans);
    int q=ans&a[deep];
    //cout<<q;
    dfs(deep+1,num+1,q);

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,pow(2,31)-1);
    cout<<mx;
    return 0;
}
