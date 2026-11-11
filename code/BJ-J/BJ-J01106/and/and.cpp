#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],vis[25],p[25],s1[200005],s2[200005],cnt[5],mx,f=1,ans,h=1;
void dfs(int s,int sum){
    if(s==m+1){
        ans=max(ans,sum);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(s+1,sum&a[i]);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>3){
            f=0;
        }
        if(a[i]!=i-1){
            h=0;
        }
    }
    if(n<=20){
        for(int i=1;i<=n;i++){
            vis[i]=1;
            dfs(2,a[i]);
            vis[i]=0;
        }
        cout<<ans;
    }
    else if(m==1){
        for(int i=1;i<=n;i++){
            mx=max(mx,a[i]);
        }
        cout<<mx;
    }
    else if(m==n){
        mx=a[1];
        for(int i=2;i<=n;i++){
            mx&=a[i];
        }
        cout<<mx;
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mx=max(mx,a[i]&a[j]);
            }
        }
        cout<<mx;
    }
    else if(m==n-1){
        s1[1]=a[1];
        for(int i=2;i<=n;i++){
            s1[i]=s1[i-1]&a[i];
        }
        s2[n]=a[n];
        for(int i=n-1;i>=1;i--){
            s2[i]=s2[i+1]&a[i];
        }
        mx=max(s1[n-1],s2[2]);
        for(int i=2;i<n;i++){
            mx=max(mx,s1[i-1]&s2[i+1]);
        }
        cout<<mx;
    }
    else if(f==1){
        for(int i=1;i<=n;i++){
            cnt[a[i]]++;
        }
        if(m<=cnt[3]){
            cout<<3;
        }
        else if(m<=cnt[3]+cnt[2]){
            cout<<2;
        }
        else{
            cout<<0;
        }
    }
    else if(h==1){
        cout<<n-m;
    }
    else{
        sort(a+1,a+n+1);
        cout<<a[n-m+1];
    }
    return 0;
}
