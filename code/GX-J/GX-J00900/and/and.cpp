#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,cnt,a[N];
struct _{
    int id;
    bool b=1;
}q[N];
void dfs(int x,int ans){
    if(x==m){
        cnt=max(ans,cnt);
        return ;
    }
    int v=0;
    for(int i=1;i<=n;i++){
        if(q[i].b){
            q[i].b=0;
            v=q[i].id;
            if(x==0){
                dfs(x+1,v);
            }else{
                dfs(x+1,ans&v);
            }
            q[i].b=1;
        }
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int y=0;
    for(int i=1;i<=n;i++){
        cin>>q[i].id;
        a[i]=q[i].id;
        y=max(y,q[i].id);
    }
    if(m==1){
        cout<<y;
        return 0;
    }else if(m==2){
        int u=0,g=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(j==i)continue;
                u=q[i].id&q[j].id;
                g=max(u,g);
            }
        }
        cout<<g;return 0;
    }else if(m==n){
        int num=q[1].id;
        for(int i=2;i<=n;i++){
            num=num&q[i].id;
        }
        cout<<num;return 0;
    }
    if(m>800){
        sort(a+1,a+n+1);
        int jj=a[n];
        for(int i=n-1;i>n-m;i--){
            jj&=a[i];
        }
        cout<<jj;
        return 0;
    }
    dfs(0,0);
    cout<<cnt;
    return 0;
}
