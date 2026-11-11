#include<bits/stdc++.h>
using namespace std;
long long a[200010];
long long f(int x){
    long long n=1;
    for(int i=0;i<x;i++){
        n*=2;
    }
    return n;
}
long long an(int x,int y){
    int a[40]={0},b[40]={0},c[40];
    int i=0,s;
    long long ans=0;
    while(x!=0){
        a[i]=x%2;
        x/=2;
        i++;
    }
    s=i;
    i=0;
    while(y!=0){
        b[i]=y%2;
        y/=2;
        i++;
    }
    s=max(s,i);
    for(int j=0;j<s;j++){
        if(a[j]==b[j]&&a[j]==1) c[j]=1;
        else c[j]=0;
    }
    s-=1;
    //for(int j=s-1;j>=0;j--) cout<<c[j];
    for(int j=s;j>=0;j--){
        if(c[j]==0){
            s--;
            continue;
        }else{
            ans+=f(s);
            s--;
        }
    }
    return ans;
}
int main(){
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,ans=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        ans=max(ans,a[i]);
    }
    if(m==1){
        cout<<ans;
        return 0;
    }
    if(m==n){
        ans=a[0];
        for(int i=1;i<n;i++) ans=an(ans,a[i]);
        cout<<ans;
        return 0;
    }
    if(m==2){
        ans=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                //long long x=an(a[i],a[j]);
                //cout<<x<<endl;
                ans=max(ans,an(a[i],a[j]));
            }
        }
        cout<<ans;
        return 0;
    }
    cout<<0;
    return 0;
}
