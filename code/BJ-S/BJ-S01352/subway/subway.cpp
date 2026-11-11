#include<bits/stdc++.h>
using namespace std;
long long minn=0x3f,c,n,m,d,q,x,y,k,a[500010],t[500010],w[500010],sum,num,mp[9010][9010],ti[9010][9010],mp1[9010][9010];
void sub(long long st,long long en){
    if(mp[st][en]==1){
        num+=ti[st][en];
        minn=min(minn,num);
        return;
    }
    for(int i=1;i<=m;i++){
        if(mp[st][i]==1&&mp1[st][i]==0){
            mp1[st][i]=1;
            mp1[i][st]=1;
            num+=ti[st][i];
            sub(i,en);
        }
    }
    num=0;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
        }
        for(long long j=1;j<=k;j++){
            for(long long l=j+1;l<=k;l++){
                mp[a[j]][a[l]]=1;
                mp[a[l]][a[j]]=1;
                ti[a[j]][a[l]]=t[j]+t[l];
                ti[a[l]][a[j]]=t[j]+t[l];
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        num+=w[x]+w[y];
        minn=0x3f;
        for(long long j=1;j<=m;j++){
            for(long long l=1;l<=m;l++){
                mp1[j][l]=0;
            }
        }
        sub(x,y);
        cout<<minn<<endl;
    }
    return 0;
}
