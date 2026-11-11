#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000005];
int times[305][305][305];
int mincnt[305][305];
int n,d;
void dfs(int q,int st,int end,int cnt){
    if(end==st){
        times[q][end][cnt]++;
        mincnt[q][end]=min(mincnt[q][end],cnt);
        return;
    }
    for(int i=st+1;i<=end;i++){
        if(a[i]-a[st]<=d) dfs(q,i,end,cnt+1);
        else break;
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=0;k<=n;k++){
                    for(int s=0;s<=n;s++){
                        mincnt[k][s]=LLONG_MAX;
                    }
                }
                dfs(i,i,j,0);
                for(int k=1;k<=n;k++){
                    for(int s=1;s<=n;s++){
                        if(times[k][s][mincnt[k][s]]==2){
                            ans++;
                        }
                    }
                }
                for(int k=0;k<=n;k++){
                    for(int s=0;s<=n;s++){
                        for(int h=0;h<=n;h++){
                            times[k][s][h]=0;
                        }
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
}