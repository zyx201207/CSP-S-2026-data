#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,minj,cnt;
int x[2000005];
struct part{
    int l,r;
};
void dfs(int p,int e,int jump){
    if(p==e){
        if(jump<minj) minj=jump,cnt=1;
        else if(jump==minj) cnt++;
        return ;
    }
    for(int i=p+1;i<=e;i++){
        if(x[i]-x[p]<=d) dfs(i,e,jump+1);
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin>>c>>T;
    while(T--){
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(c==11||c==12){
            int l=x[n]-x[n-1],zero=0;
            if(l<d) ans=max(zero,n-max(zero,d/l)*2+1);
        }
        else{
            for(int i=1;i<n-2;i++){
                for(int j=i+3;j<=n;j++){
                    cnt=0,minj=2000000000000000000;
                    dfs(i,j,0);
                    if(cnt==2) ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
