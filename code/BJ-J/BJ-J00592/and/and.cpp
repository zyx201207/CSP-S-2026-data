#include<bits/stdc++.h>
using namespace std;
int n,m,o[200005],ans[200005],u[200005],p=1;
int awy(int x,int y){
    int a[64],p=1;
    while(x>0){
        a[p]=x-x/2*2;
        p++;
        x/=2;
    }
    int b[64],q;
    while(y>0){
        b[q]=y-y/2*2;
        q++;
        y/=2;
    }
    int e=max(p,q);
    for(int i=e-1;i>=1;i--)
        swap(b[i],b[e-i-1]);
    for(int i=e-1;i>=1;i--)
        swap(a[i],a[e-i-1]);
    int c[64];
    for(int i=1;i<=e-1;i++){
        if(a[i]==b[i]){
            c[i]=1;
        }
        else{
            c[i]=0;
        }
    }
    int ans=0;
    for(int i=1;i<=e-1;i++){
        ans+=pow(2,e-1-i);
    }
    return ans;
}
void dfs(int pos){
    if(pos>m){
        int b=pow(2,30);
        b-=1;
        for(int i=1;i<=n;i++){
            b=awy(o[i]*u[i],b);
        }
        ans[p]=b;
        cout<<b<<endl;
        p++;
        return ;
    }
    for(int i=pos;i<=n;i++){
        if(!u[i]){
            u[i]=1;
            //cout<<i<<endl;
            dfs(pos+1);
            u[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>o[i];
    }
    dfs(1);
    int maxn=0;
    for(int i=1;i<p;i++){
        maxn=max(maxn,ans[i]);
    }
    cout<<maxn;
    return 0;
}
