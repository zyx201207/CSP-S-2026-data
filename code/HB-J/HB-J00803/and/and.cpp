#include<bits/stdc++.h>
using namespace std;

int n,m,maxn=0;
int vis[30];
int a[200010];

bool cmp(int a,int b){
    return a>b;
}

int dfs(int s,int pos){
    if(s>=m){
        int res=INT_MAX;
        for(int i=1;i<=n;i++){
            if(vis[i]){
                res&=a[i];
            }
        }
        return res;
    }
    int res=0;
    for(int i=pos+1;i<=n;i++){
        vis[i]=1;
        res=max(dfs(s+1,i),res);
        vis[i]=0;
    }
    return res;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    bool ta=1,tb=1,tc=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i-1) tb=0;
        if(a[i]>3) tc=0;
        int g=a[i];
        while(g!=0&&ta){
            if(!g&1){
                ta=0;
                break;
            }
            g/=2;
        }
        maxn=max(maxn,a[i]);
    }
    if(m==1){//6
        cout<<maxn;
    }else if(m==n){//7
        int res=a[1];
        for(int i=2;i<=n;i++){
            res&=a[i];
        }
        cout<<res;
    }else if(m==2&&n<=10000){//8-10
        int res=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                res=max(res,a[i]&a[j]);
            }
        }
        cout<<res;
    }else if(ta){//13
        sort(a+1,a+n+1,cmp);
        cout<<a[m];
    }else if(tc){//16-17
        int cnt[5]={};
        for(int i=1;i<=n;i++){
            cnt[a[i]]++;
        }
        if(cnt[3]>=m) cout<<3;
        else if(cnt[3]+cnt[2]>=m) cout<<2;
        else if(cnt[3]+cnt[1]>=m) cout<<1;
        else cout<<0;
    }else if(n<=20){//1-5
        cout<<dfs(1,0);
    }
    //5+5+15+5+10+25=65pts
    return 0;
}
