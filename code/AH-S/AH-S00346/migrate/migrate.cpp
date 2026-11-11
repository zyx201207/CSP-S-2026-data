#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5010;
int c,T,n,d,cishu,ans;
int x[N],dt[N][N];
void dfs(int l,int p,int r,int t){
    //cout<<l<<" "<<p<<" "<<r<<" "<<t<<" "<<endl;
    if(t==dt[l][r]){
        if(p==r){
            cishu++;
        }
        return;
    }
    int tp=p+1;
    while(x[tp]-x[p]<=d&&tp<=r){
        dfs(l,tp,r,t+1);
        tp++;
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            int r=i,cnt=0;
            while(upper_bound(x+1,x+n+1,x[r]+d)-x!=-1){
                int tr=upper_bound(x+1,x+n+1,x[r]+d)-x-1;
                if(r==tr){
                    break;
                }
                cnt++;
                for(int j=r+1;j<=tr;j++){
                    dt[i][j]=cnt;
                }
                r=tr;
            }
            if(dt[r+1]-dt[r]<=d){
                cnt++;
                for(int j=r+1;j<=n;j++){
                    dt[i][j]=cnt;
                }
            }
            int l=i;
            cnt=0;
            while(lower_bound(x+1,x+n+1,x[l]-d)-x!=-1){
                int tl=lower_bound(x+1,x+n+1,x[l]-d)-x;
                if(l==tl){
                    break;
                }
                cnt++;
                for(int j=tl;j<=l-1;j++){
                    dt[i][j]=cnt;
                }
                l=tl;
            }
        }
        /*
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<dt[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(dt[i][j]==0){
                    continue;
                }
                cishu=0;
                dfs(i,i,j,0);
                if(cishu==2){
                    //cout<<i<<" "<<j<<endl;
                    ans++;
                }
                //cout<<"OK"<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
