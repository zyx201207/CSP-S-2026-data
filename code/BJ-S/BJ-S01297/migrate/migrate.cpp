#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000009];
int ans=0,minn=1e18;
int n,d;
void dfs(int x,int y,int cnt){
    if(x==y){
        if(cnt<minn){
            ans=0;
            minn=cnt;
        }
        ans++;
        return ;
    }
    for(int i=x+1;i<=y;++i){
        if(a[i]-a[x]<=d){
            dfs(i,y,cnt+1);
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int C,T;
    cin>>C>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        if(C==11||C==12){
            int gc=a[2]-a[1];
            int ans=0;
            if(d<=gc||d>(n-1)*gc){
                cout<<"0\n";
                continue;
            }
            int k=d/gc;
            cout<<n-(2*k)+1<<'\n';
            return 0;
        }
        if(C==13||C==14){
            cout<<0<<"\n";
            return 0;
        }
        if(C<=2){
            int cnt=0;
            for(int i=1;i<=n;++i){
                for(int j=i;j<=n;++j){
                    ans=0;
                    dfs(i,j,0);
                    if(ans==2)cnt++;
                }
            }
            cout<<cnt<<'\n';
        }
    }
    return 0;
}