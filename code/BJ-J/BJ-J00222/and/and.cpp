#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=0;
int a[200005];
int ma=0;
int qq=INT_MAX;
bool v[200005];
void dfs(int x,int sum,int cnt){
    if(x==n+1){
        if(cnt==m)ma=max(ma,sum);
        return ;
    }
    v[x]=0;
    dfs(x+1,sum,cnt);
    v[x]=1;
    dfs(x+1,(sum&a[x]),cnt+1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        qq&=a[i];
        ma=max(ma,a[i]);
    }
    if(m==1)cout<<ma;
    else if(m==2){
        ma=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ma=max(ma,(a[i]&a[j]));
            }
        }
        cout<<ma;
    }else if(m==n){
        cout<<qq;
    }else{
        ma=0;
        dfs(1,INT_MAX,0);
        cout<<ma;
    }
    return 0;
}
