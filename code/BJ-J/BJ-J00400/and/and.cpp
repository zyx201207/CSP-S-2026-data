#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m;
int maxn;
bool use[200005];
void dfs(int p,int an,int cnt){
    if(cnt==m+1){
        maxn=max(maxn,an);
        return;
    }
    if(p==n+1){
        return;
    }
    if(!use[p]){
        use[p]=1;
        dfs(p+1,an&a[p],cnt+1);
        use[p]=0;
    }
    dfs(p+1,an,cnt);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int maxn1=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
       maxn1=max(maxn1,a[i]);
    }
    if(m==1)cout<<maxn1;
    else if(m==n){
        int t=a[1];
        for(int i=2;i<=n;i++)t&=a[i];
        cout<<t;
    }else if(n<=20){
        dfs(1,pow(2,n)-1,0);
        cout<<maxn;
    }

    return 0;
}
