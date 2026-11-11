#include<bits/stdc++.h>
using namespace std;
long long n,m, a[200005],ma=-1,ans=1048575,sum=-1,b[200005],F=1,tx4;
void dfs(int x,int dep){
    if(x==n+1){
        ans=1048575;
        if(dep!=m)  return ;
        for(int i=1;i<=n;i++){
            if(b[i])    ans=ans&a[i];
        }
        sum=max(sum,ans);
        return ;
    }
    b[x]=1;
    dfs(x+1,dep+1);
    b[x]=0;
    dfs(x+1,dep);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        tx4=max(tx4,a[i]);
        ans=ans&a[i];
        long long txa=1,f=0;
        for(int j=1;j<=20;j++){
            txa*=2;
            if(a[i]==txa-1){
                f=1;
                break;
            }
        }
        if(f==0)    F=0;
    }
    if(n<=20){
        dfs(1,0);
        cout<<sum;
        return 0;
    }
    else if(m==1){
        sort(a+1,a+n+1);
        cout<<a[n];
        return 0;
    }
    else if(m==n){
        cout<<ans;
        return 0;
    }
    else if(m==2){
        ma=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ma=max(ma,a[i]&a[j]);
            }
        }
        cout<<ma;
        return 0;
    }
    else if(m==n-1){
        ma=-1;
        for(int i=1;i<=n;i++){
            ans=1048575;
            for(int j=1;j<=n;j++){
                if(j!=i)    ans=ans&a[j];
            }
            ma=max(ma,ans);
        }
        cout<<ma;
        return 0;
    }
    else if(F==1){
        sort(a+1,a+n+1);
        cout<<a[n-m+1];
        return 0;
    }else if(tx4<=4){
        int a1=0,b1=0,c1=0,d1=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1) a1++;
            if(a[i]==2) b1++;
            if(a[i]==3) c1++;
            if(a[i]==4) d1++;
        }
        //cout<<a1<<" "<<b1<<" "<<c1<<" "<<d1<<endl;
        if(m<=d1){cout<<4;return 0;}
        if(m<=c1){cout<<3;return 0;}
        if(m<=b1){cout<<2;return 0;}
        if(m<=c1+b1){   cout<<2;return 0;}
        if(m<=a1){cout<<1;return 0;}
        if(m<=c1+a1){   cout<<1;return 0;}
        cout<<0;
        return 0;
    }else{
        cout<<0;
    }
    return 0;
}
