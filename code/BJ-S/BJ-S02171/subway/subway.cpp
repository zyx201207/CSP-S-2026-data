#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q,k;
struct node{
    ll w,a[25],an,t[25],tn;
}zh[500010];

ll line[510][510];//G
ll dp[510][510];//to floyd
ll s,tt,ans;
void edge(int u,int v,ll w){
    line[u][v]=line[v][u]=min(line[u][v],w);
    dp[u][v]=dp[v][u]=line[u][v];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    //cin>>c>>n>>m>>d>>q;
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        //cin>>zh[i].w;
        scanf("%lld",&zh[i].w);
    }
    for(int i=1;i<=n;i++){
        //cin>>k;
        scanf("%lld",&k);
        for(int j=1;j<=k;j++){
            ll tmp=0,tmp2=0;
            //cin>>tmp>>tmp2;
            scanf("%lld%lld",&tmp,&tmp2);
            zh[tmp].t[++zh[tmp].tn]=tmp2;
            zh[tmp].a[++zh[tmp].an]=i;
        }
    }
    memset(line,0x3f,sizeof(dp));
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=zh[i].an;j++){
            for(int k=1;k<j;k++){
                edge(zh[i].a[j],zh[i].a[k],zh[i].t[j]+zh[i].t[k]);
            }
        }
    }
    //floyd
    for(int i=1;i<=n;i++)dp[i][i]=0;
    for(int l=1;l<=n;l++){
        for(int r=l+1;r<=n;r++){
            for(int mid=l;mid<=r;mid++){
                dp[r][l]=dp[l][r]=min(dp[l][r],dp[l][mid]+dp[mid][r]);
            }
        }
    }

    while(q--){
        //cin>>s>>tt;
        scanf("%lld%lld",&s,&tt);
        ll so_w=zh[s].w+zh[tt].w;
        ans=1e18;
        for(int i=1;i<=zh[s].an;i++){
            int sa=zh[s].a[i];
            for(int j=1;j<=zh[tt].an;j++){
                int ta=zh[tt].a[j];
                ll t_w=zh[s].t[i]+zh[tt].t[j];
                ans=min(ans,t_w+so_w+dp[sa][ta]);
                //cout<<t_w+so_w+dp[sa][ta]<<" updata!\n";
            }
        }
        //cout<<ans<<'\n';
        printf("%lld\n",ans);
    }
    return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
