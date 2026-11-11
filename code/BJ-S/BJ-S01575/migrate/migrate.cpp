//(te shu xing zhi A) and (n^3 baoli)
//8+24=32
#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int x[2000005];
int fr[200005];
int f[305][305];
int dis[305][305];
void slv1(){
    cin>>n>>d;
    for (int i=1;i<=n;i++){
        cin>>x[i];
    }
    int dis=x[n]-x[n-1];
    if (d<2*dis){
        cout<<"0\n";
        return ;
    }
    int bs=d/dis;
    int ans=n-bs-1;
    cout<<ans<<"\n";
    return ;
}
void slv2(){
    cin>>n>>d;
    for (int i=1;i<=n;i++){
        cin>>x[i];
        fr[i]=i;
    }
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            f[i][j]=0;
            dis[i][j]=0;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            if (x[j]-x[i]<=d){
                fr[i]=j;
            }
            else{
                j=n+1;
            }
        }
    }
    for (int i=1;i<n;i++){
        if (x[i+1]-x[i]<=d){
            f[i][i+1]=1;
            dis[i][i+1]=1;
        }
    }
    int cnt=0;
    for (int del=2;del<=n;del++){
        for (int st=1;st+del<=n;st++){
            int ed=st+del;
            if (x[ed]-x[st]<=d){
                f[st][ed]=1;
                dis[st][ed]=1;
                continue;
            }
            int minn=10000000000000;
            for (int zz=st+1;zz<ed;zz++){
                if (dis[st][zz]==0 or dis[zz][ed]==0){
                    continue;
                }
                minn=min(minn,dis[st][zz]+dis[zz][ed]);
            }
            if (minn!=10000000000000){
                dis[st][ed]=minn;
            }
            else{
                continue;
            }
            //
            // if (st==1 and ed==5){
            //     cout<<"ZZZZZZZ minn "<<minn<<'\n';
            // }
            //
            for (int zz=st+1;zz<ed;zz++){
                if (dis[st][zz]+dis[zz][ed]!=minn or dis[st][zz]!=1){
                    continue;
                }
                f[st][ed]+=f[st][zz]*f[zz][ed];
                //
                // if (st==1 and ed==5) cout<<"ZZZZZZ "<<zz<<"\n";
                //
            }
            if (f[st][ed]==2){
                cnt++;
                // cout<<st<<" "<<ed<<"\n";
            }
        }
    }
    cout<<cnt<<"\n";
    return ;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while (t--){
        if (c==11 or c==12){
            slv1();
            continue;
        }
        slv2();//n^3 bao li
    }
    return 0;
}