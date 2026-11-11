#include<bits/stdc++.h>
using namespace std;
int n,m;
long long sum;
long long a[200010];
int f[200010];
long long b[200010];
long long cmp(long long p,long long q){
    return p>q;
}
void dfs(int x,long long p){
    if(x==m+1){
        sum=max(sum,p);
        return ;
    }
    if(x==1){
        for(int i=1;i<=n;i++){
            if(!f[i]){
                f[i]=1;
                b[x]=a[i];
                dfs(x+1,a[i]);
                f[i]=0;
            }
        }
    }else{
        for(int i=1;i<=n;i++){
            if(!f[i]){
                f[i]=1;
                b[x]=a[i];
                dfs(x+1,(p&a[i]));
                f[i]=0;
            }
        }
    }
    return ;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n<=20){
        dfs(1,0);
        cout<<sum;
        return 0;
    }else if(m==1){
        sort(a+1,a+n+1,cmp);
        cout<<a[1];
        return 0;
    }else if(m==n){
        long long w=a[1];
        for(int i=2;i<=n;i++)
            w&=a[i];
        cout<<w;
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    long long ans=a[1];
    for(int i=2;i<=m;i++){
        ans&=a[i];
    }
    cout<<ans;
    return 0;
}
