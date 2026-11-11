#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[50005],k[505],a2[505][50005],a[505][50005],t[505][50005],x,y,minn,carry1,carry2,tim;
bool b[50005];
void finda(long long s,long long si,long long f){
    if(a[si][f]==1){
        minn=min(minn,tim+t[si][f]);
        return;
    }
    else{
        for(int i=1;i<=k[si];i++){
            for(int j=1;j<=m;j++){
                if(a[si][a2[si][i]]&&a[j][a2[si][i]]){
                    tim+=t[si][a2[si][i]]+t[j][a2[si][i]];
                    b[a2[si][i]]=1;
                    finda(a2[si][i],j,f);
                    tim-=t[si][a2[si][i]]+t[j][a2[si][i]];
                    b[a2[si][i]]=0;
                }
            }
        }
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a2[i][j]>>carry2;
            a[i][a2[i][j]]=1;
            t[i][a2[i][j]]=carry2;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        tim=w[x]+w[y];
        minn=1000005;
        for(int i=1;i<=n;i++){
            if(a[i][x]){
                for(int j=1;j<=k[i];j++){
                    tim+=t[i][x];
                    b[x]=1;
                    finda(a2[i][j],i,y);
                    tim-=t[i][x];
                    b[x]=0;
                }
            }
        }
    }
    return 0;
}
