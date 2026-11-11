#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int MAXN=2*1e5+5;
int a[MAXN];
int ans=-1;
int n,m;

void dfs(int i,int cur,int depth){
    if(depth==n+1&&i==m){
        ans=max(ans,cur);
        return ;
    }
    if(i==m){
        return ;
    }
    if(depth==n+1){
        return ;
    }
    dfs(i+1,cur&a[depth],depth+1);
    dfs(i,cur,depth+1);
}

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    if(n<=20){
        if(m==1){
            int t=-1;
            for(int i=1;i<=n;i++){
                t=max(t,a[i]);
            }
            cout<<t<<endl;
        }
        else{
            dfs(1,2147483647,1);
            cout<<ans<<endl;
        }
    }
    else if(n<=2000){
        if(m==1){
            int t=-1;
            for(int i=1;i<=n;i++){
                t=max(t,a[i]);
            }
            cout<<t<<endl;
        }
        else if(m==n){
            int t=2147483647;
            for(int i=1;i<=n;i++){
                t=t&a[i];
            }
            cout<<t<<endl;
        }
        else{
            int t=-1;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i!=j){
                        t=max(t,a[i]&a[j]);
                    }
                }
            }
            cout<<t<<endl;
        }
    }
    else{
        if(m==n-1){
            int t=-1;
            for(int i=1;i<=n;i++){
                int x=2147483647;
                for(int j=1;j<=n;j++){
                    if(j==i){
                        continue;
                    }
                    else{
                        x=x&a[j];
                    }
                }
                t=max(t,x);
            }
            cout<<t<<endl;
        }
        else{
            int t=-1;
            for(int i=1;i<=n;i++){
                t=max(t,a[i]);
            }
            cout<<t<<endl;
        }
    }

    return 0;
}
