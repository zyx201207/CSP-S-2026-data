#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[3000000],nxt[3000000],bas[3000000];
struct uque{
    int l,r,x;
}q[300000];
pair<int,int> dp[3000000];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        int ans=0;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<=n;i++){
            nxt[i]=nxt[i-1];
            while(nxt[i]<n && x[nxt[i]+1]-x[i]<=d) nxt[i]++;
        }
        for(int j=2;j<=n;j++){
            for(int i=0;i<=n;i++) bas[i]=0;
            bas[0]=1;
            int l=1,r=0;
            q[++r]={j,j,0};
            dp[j].first=0,dp[j].second=1;
            for(int i=j-1;i>0;i--){
                for(int k=nxt[i]+1;k<=nxt[i+1] && k<=j;k++){
                    bas[dp[k].first]-=dp[k].second;
                }
                if(nxt[i]==i) break;
                while(r>=l && x[q[l].r]>x[i]+d){
                    l++;
                }
                dp[i].first=q[l].x+1;
                dp[i].second=bas[dp[i].first-1];
                if(dp[i].second==2){
                    ans++;
                }
                bas[dp[i].first]+=dp[i].second;
                int nl=i;
                while(r>=l && q[r].x>=dp[i].first){
                    nl=q[r].l;
                    r--;
                }
                q[++r]={nl,i,dp[i].first};
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}

