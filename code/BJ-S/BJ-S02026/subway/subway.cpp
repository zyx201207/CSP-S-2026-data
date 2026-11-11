#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500010];
long long k[510];
long long a[510][500010];
long long t[510][500010];
long long tt[510][500010];
long long td[500010][30];
long long tp[500010];
long long huann[510][510];
void mainn(){
    memset(huann,0x3f3f3f,sizeof(huann));
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++){
        cin>>w[i];
    }
    for(long long i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j];
            cin>>t[i][j];
            tt[i][a[i][j]]=t[i][j];
            td[a[i][j]][++tp[a[i][j]]]=i;
        }
    }
    for(long long i=1;i<=n;i++){//建图
        for(long long j=1;j<=n;j++){
            for(long long p=1;p<=k[i];p++){
                if(t[j][a[i][p]]!=0){
                    huann[i][j]=min(huann[i][j],t[i][p]+tt[j][a[i][p]]);
                    huann[j][i]=min(huann[j][i],t[i][p]+tt[j][a[i][p]]);
                }
            }
        }
    }
    for(long long p=1;p<=n;p++){//floyd算法，转折点
        for(long long i=1;i<=n;i++){//起点
            for(long long j=1;j<=n;j++){//终点
                if(huann[i][p]+huann[p][j]<huann[i][j]){
                    huann[i][j]=huann[i][p]+huann[p][j];
                    huann[j][i]=huann[i][p]+huann[p][j];
                }
            }
        }
    }
    for(long long p=1;p<=q;p++){
        long long x,y,ans=46116860140000000;
        cin>>x>>y;
        for(long long i=1;i<=tp[x];i++){
            for(long long j=1;j<=tp[y];j++){
                ans=min(ans,k[x]+k[y]+huann[i][j]+td[x][i]+td[y][j]);
            }
        }
        cout<<ans<<endl;
    }
}
int main(){
    mainn();
    return 0;
}
