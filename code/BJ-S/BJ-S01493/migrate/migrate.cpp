#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
int c,t,n,d;
const int N=5050;
const int M=2e6+50;
int f[N][N];//number of solution
int dis[N][N];//mi dist
int ind[M];
int cnt[M];
int q[M];//queue
int ans=0;
void cal_dis(){
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++)dis[i][j]=1e8;
        dis[i][i]=0;
        int bg=1,ed=0;
        for(int j=i;j<=n;j++){
            //cout<<q[bg]<<" "<<q[ed]<<"\n";
            while(ed>=bg && ind[j]-ind[q[bg]]>d)++bg;
            if(i!=j && bg<=ed)
            dis[i][j]=dis[i][q[bg]]+1;
            while(ed>=bg && dis[i][q[ed]]>=dis[i][j])--ed;
            q[++ed]=j;
            //cout<<i<<" "<<j<<" "<<dis[i][j]<<"\n";
        }
    }
}
void cal_f(){
    for(int i=n;i>=1;i--){
        for(int j=0;j<=n;j++){
            f[i][j]=0;
            cnt[j]=0;
        }
        f[i][i]=1;
        cnt[0]=1;
        int bg=i;
        int sum=0;
        //cout<<"I:"<<i<<"\n";
       // if(i==5)
        for(int j=i+1;j<=n;j++){
            if(dis[i][j]>n)break;
            //cout<<"J:"<<j<<"\n";
            //cout<<bg<<"\n";
            //cout<<ind[j]-ind[bg]<<"\n";
            while(bg<j && ind[j]-ind[bg]>d){
                //cout<<"DIS:"<<i<<" "<<bg<<" "<<dis[i][bg]<<"\n";
                if(dis[i][bg]<=n)
                cnt[dis[i][bg]]-=f[i][bg];
                ++bg;
            }
            //if(dis[i][j]>=1)
            f[i][j]=cnt[dis[i][j]-1];
            cnt[dis[i][j]]+=f[i][j];
            //else f[i][j]=0;
            //cout<<i<<" "<<j<<" "<<f[i][j]<<"\n";
            if(f[i][j]==2)++ans;
        }
    }
}
void work(){
    cin>>n>>d;
    bool flag=1;
    int c=(ind[2]-ind[1]);
    for(int i=1;i<=n;i++){
        cin>>ind[i];
        if(i>=2 && ind[i]-ind[i-1]!=c)flag=0;
    }
    if(n>5000){
        int step=(d+c-1)/c;
       cout<<max(0ll,n-step-1*(n-step)/2)<<"\n";
       return;
    }
    ans=0;
    cal_dis();cal_f();
    //cout<<"DIS222:"<<dis[5][8]<<"\n";
    cout<<ans<<"\n";
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        work();
    }
    return 0;
}
