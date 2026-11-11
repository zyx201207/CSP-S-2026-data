#include<bits/stdc++.h>
using namespace std;
int n,m,total,maxa,a[200005];
void dfs(int pos,int cnt,int maxa,int ans){
    if(cnt==m){
        maxa=max(maxa,ans);
        return;
    }
    dfs(pos+1,cnt+1,maxa,(ans&a[pos+1]));
    dfs(pos+1,cnt,maxa,ans);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m>>a[1];
    sort(a+1,a+n+1);
    if(m==1) cout<<a[n];
    else if(m==n){
        total=a[1];
        for(int i=2;i<=n;i++){
            cin>>a[i];
            total&=a[i];
        }
        cout<<total;
    }
    else if(m==n-1){
        total=a[2];
        for(int i=3;i<=n;i++) total&=a[i];
        maxa=max(maxa,total);
        total=a[1];
        for(int i=2;i<=n;i++){
            for(int j=2;j<=n&&j!=i;j++) total&=a[j];
            maxa=max(maxa,total);
        }
        cout<<maxa;
    }
    else if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if((a[i]&a[j])>maxa) maxa=(a[i]&a[j]);
            }
        }
        cout<<maxa;
    }
    else{
        dfs(0,0,0,2147483647);
        cout<<maxa;
    }
    return 0;
}
