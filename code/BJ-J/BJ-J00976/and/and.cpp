#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=-1;
bool cmp(int x,int y){
    return x>y;
}
void dfs(int pos,int x,int andd){
    //cout<<pos<<' '<<x<<' '<<andd<<'\n';
    if(pos==m){
        ans=max(ans,andd);
        return;
    }
    if(x>n){
        return;
    }
    dfs(pos+1,x+1,andd&a[x]);//choose
    dfs(pos,x+1,andd);//don't choose
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        dfs(0,1,2147483647);
        cout<<ans;
        return 0;
    }
    else if(n<=2000&&m==1){
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
        cout<<ans;
        return 0;
    }
    else if(n<=2000&&m==n){
        ans=2147483647;
        for(int i=1;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    else if(n<=2000&&m==2){
        dfs(0,1,2147483647);
        cout<<ans;
        return 0;
    }
    else if(m==n-1){
        int cnt=2147483647;
        for(int i=1;i<=n;i++){
            cnt&=a[i];
        }
        for(int i=1;i<=n;i++){
            ans=max(ans,cnt|(~a[i]));
        }
        return 0;
    }
    else{
        ans=2147483647;
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=m;i++){
            ans&=a[i];
        }
        cout<<ans;
    }
    return 0;
}