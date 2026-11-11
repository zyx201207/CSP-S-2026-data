#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,a[200005];
long long f[200005],g[200005];
long long dfs(int x,int cnt,long long sum){
    if(cnt==m){
        //cout<<x<<" "<<cnt<<" "<<sum<<endl;
        //for(int i=1;i<=n;i++) cout<<vis[i];
        //cout<<endl;
        return sum;
    }
    if(x>n) return 0;
    long long maxans=0;
    maxans=dfs(x+1,cnt,sum);
    //vis[x]=true;
    maxans=max(maxans,dfs(x+1,cnt+1,(sum&a[x])));
    //vis[x]=false;
    return maxans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){//6
        int maxa=0;
        for(int i=1;i<=n;i++){
            maxa=max(maxa,a[i]);
        }
        cout<<maxa;
    }else if(m==n){//7
        long long ans=(long long)(1<<31)-1;
        for(int i=1;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
    }else if(m==2){//8-10
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }else if(m==n-1){//11-12
        f[0]=(long long)(1<<31)-1;
        for(int i=1;i<=n;i++){
            f[i]=(f[i-1]&a[i]);
        }
        g[n+1]=(long long)(1<<31)-1;
        for(int i=n;i>=1;i--){
            g[i]=(g[i+1]&a[i]);
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,f[i-1]&g[i+1]);
        }
        cout<<ans;
    }else if(n<=20){//1-5
        cout<<dfs(1,0,(long long)(1<<31)-1);
    }else{//A
        int maxa=0;
        for(int i=1;i<=n;i++){
            maxa=max(maxa,a[i]);
        }
        cout<<maxa;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
