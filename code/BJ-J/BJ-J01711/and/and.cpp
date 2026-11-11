#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[10000005];
int t[10000005];
int ans=-1;
void dfs(int start,int pos){
    if(start==m+1){
        int sum=t[1];
        for(int i=1;i<=m;i++){
            sum&=t[i];
        }
        ans=max(ans,sum);
    }
    for(int i=pos;i<=n;i++){
        t[start]=a[i];
        dfs(start+1,i+1);
    }
}
void f1(){
    int ans=-1;
    for(int i=1;i<=n;i++){
        ans=max(ans,a[i]);
    }
    cout<<ans;
}
void f2(){
    int ans=-1;
    for(int i=1;i<n;i++){
            int sum=a[1];
        for(int j=i+1;j<=n;j++){
            sum=a[i]&a[j];
            ans=max(ans,sum);
        }
    }
    cout<<ans;
}
void f3(){
    int sum=a[1];
    for(int i=1;i<=n;i++){
        sum&=a[i];
    }
    cout<<sum;
}
void f4(){
    int ans=-1;
    int sum;
    for(int k=1;k<=n;k++){
        if(k==1)sum=a[2];
        else sum=a[1];
        for(int i=1;i<=n;i++){
            if(i==k)continue;
            sum&=a[i];
        }
        ans=max(ans,sum);
    }
    cout<<ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
            cin>>a[i];
    }
    if(n<=20){
        dfs(1,1);
        cout<<ans<<endl;
        return 0;
    }
    if(m==1){
        f1();
        return 0;
    }
    if(m==2){
        f2();
        return 0;
    }
    if(m==n){
        f3();
        return 0;
    }
    if(m==n-1){
        f4();
        return 0;
    }
    return 0;
}
