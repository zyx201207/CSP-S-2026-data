#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],v[200001],ans,maa;
int b[2000001];
void dfs(int x,int k){
    if(x==n+1){
        if(k!=m)return;
        int o=0;
        for(int i=1;i<=n;i++)if(v[i]==1){
            if(!o)o=a[i];
            else o&=a[i];
        }
        ans=max(ans,o);
        return;
    }
    dfs(x+1,k);
    v[x]=1;
    dfs(x+1,k+1);
    v[x]=0;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]++;
        maa=max(maa,a[i]);
    }
    if(m==n){
        int ppppp=a[1];
        for(int i=2;i<=n;i++)ppppp&=a[i];
        cout<<ppppp;
    }
    else if(m==1){
        int ma=0;
        for(int i=1;i<=n;i++)ma=max(ma,a[i]);
        cout<<ma;
    }
    else if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }
    else if(m==n-1){
        int mi=INT_MAX,p=-1,ppppp;
        for(int i=1;i<=n;i++){
            if(a[i]<mi&&b[a[i]]!=2){
                mi=a[i];
                p=i;
            }
        }
        if(p==1){
            ppppp=a[2];
            for(int i=3;i<=n;i++)ppppp&=a[i];
        }
        else{
            ppppp=a[1];
            for(int i=2;i<=n;i++){
                if(i==p)continue;
                ppppp&=a[i];
            }
        }
        cout<<ppppp;
    }
    else if(n<=20){
        dfs(1,0);
        cout<<ans;
    }
    else{
            if(maa<=4){
            int b1=b[1],b2=b[2],b3=b[3],b4=b[4];
            if(b4>=m)cout<<4;
            else{
                if(b[3]>=m)cout<<3;
                else{
                    if(b[2]+b[3]>=m)cout<<2;
                    else{
                        if(b[1]+b[3]>=m)cout<<1;
                        else cout<<0;
                    }
                }
            }
            return 0;
        }

        sort(a+1,a+1+n,greater<int>());
        int ppppp=a[1];
        for(int i=2;i<=m;i++)ppppp&=a[i];
        cout<<ppppp;
    }
    return 0;
}
