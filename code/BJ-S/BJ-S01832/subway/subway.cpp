#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a,t,xr,yr,kk,ans;
long long w[500005];
long long ds[1005][1005];
vector<pair<long long,long long> >qwq[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(long long i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            if(i==j){ds[i][j]=0;continue;}
            ds[i][j]=-1;
        }
    }
    for(long long i=1;i<=n;i++){
        scanf("%lld",&kk);
        for(long long j=1;j<=kk;j++){
            scanf("%lld%lld",&a,&t);
            qwq[a].push_back(make_pair(i,t));
        }
    }
    for(long long i=1;i<=m;i++){
        if(qwq[i].size()>1){
            for(long long j=0;j<qwq[i].size();j++){
                for(long long k=0;k<qwq[i].size();k++){
                    if(j==k)continue;
                    if(ds[qwq[i][j].first][qwq[i][k].first]==-1)
                    ds[qwq[i][j].first][qwq[i][k].first]=qwq[i][j].second+qwq[i][k].second;
                    else ds[qwq[i][j].first][qwq[i][k].first]=min
                        (ds[qwq[i][j].first][qwq[i][k].first],
                    qwq[i][j].second+qwq[i][k].second);
                }
            }
        }
    }
    //floyd
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j or i==k or k==j)continue;
                if(ds[i][k]!=-1 and ds[k][j]!=-1){
                    if(ds[i][j]==-1)ds[i][j]=ds[i][k]+ds[k][j];
                    else
                    ds[i][j]=min(ds[i][j],ds[i][k]+ds[k][j]);//cout<<i<<" "<<j<<" "<<k<<" "<<ds[i][j]<<" "<<ds[i][k]<<" "<<ds[k][j]<<endl;
                }
                else continue;

            }
        }
    }
    for(long long i=1;i<=q;i++){
        scanf("%lld%lld",&xr,&yr);
        ans=-1;
        for(int j=0;j<qwq[xr].size();j++){
            for(int k=0;k<qwq[yr].size();k++){
                if(ans==-1)ans=qwq[xr][j].second+qwq[yr][k].second
                    +ds[qwq[xr][j].first][qwq[yr][k].first];
                else{
                    ans=min(ans,qwq[xr][j].second+qwq[yr][k].second
                       +ds[qwq[xr][j].first][qwq[yr][k].first]);
                }
            }
        }
        //cout<<xr<<" "<<yr<<" ";
        printf("%lld\n",ans+w[xr]+w[yr]);
    }
    return 0;
}