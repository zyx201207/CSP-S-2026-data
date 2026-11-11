#include<bits/stdc++.h>
using namespace std;
int a[200005],flag=1;
int n,m,ans;
void dfs(int x,int c,int sum){
    if(c==m){ans=max(ans,sum);return;}
    for(int i=x+1;i<=n-m+1+c;i++){
        dfs(i,c+1,sum&a[i]);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>4)flag=0;
    }
    if(flag==1){
        int t1=0,t2=0,t3=0,t4=0,t0=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0)t1++;
            if(a[i]==1)t2++;
            if(a[i]==2)t3++;
            if(a[i]==3)t4++;
            if(a[i]==4)t0++;
        }
        if(m<=t0)cout<<4;
        else if(m<=t0+t4)cout<<3;
        else if(m<=t0+t4+t3)cout<<2;
        else if(m<=t0+t4+t3+t2)cout<<1;
        else if(m<=t0+t4+t3+t2+t1)cout<<0;
        return 0;
    }
    if(n<=20){
        for(int i=1;i<=n-m+1;i++){
            dfs(i,1,a[i]);
        }
    }
    if(n<=2000){
        if(m==1){
            for(int i=1;i<=n;i++){
                ans=max(ans,a[i]);
            }
        }
        if(m==n){
            for(int i=1;i<=n;i++){
                ans=(ans&a[i]);
            }
        }
        if(m==2){
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    ans=max(a[i]&a[j],ans);
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
