#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],maxn=-2e9,ll,f;
bool cmp(int a,int b){
    return a>b;
}
void dfs(int m,int i,int ans,int zhi){
    if(f==1){
        return;
    }
    if(ans<=maxn&&zhi==1){
        return;
    }
    if(m==0){
        if(ans>maxn){
            maxn=ans;
            if(ans==ll){
                f=1;
                return;
            }
        }
        return;
    }
    if(i>n){
        return;
    }
    if(zhi==1){
        dfs(m-1,i+1,a[i+1]&ans,1);
    }
    else{
        dfs(m-1,i+1,a[i+1],1);
    }
    dfs(m,i+1,ans,zhi);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>ll){
            ll=a[i];
        }
    }
    int k=a[1];
    if(m==n){
        for(int i=2;i<=n;i++){
            k=k&a[i];
        }
        cout<<k;
        return 0;
    }
    if(m==1){
        cout<<ll;
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    dfs(m,0,0,0);
    if(maxn==-2e9){
        maxn=0;
    }
    cout<<maxn;
    return 0;
}
