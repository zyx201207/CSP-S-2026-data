#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000003],b[2000003];
int road[2000003];
int ans;
static void dfs(int p,int w,int f,long long steps){
    //cout<<p<<' '<<steps<<' '<<b[p]<<endl;
    if(steps==b[p]&&steps>1){
        road[p]++;
    }else if(steps<b[p]&&steps>1){
        road[p]=1;
        b[p]=min(b[p],steps);
    }
    if(p==f){
        return;
    }
    int farthest=w+d;
    for(int i=p+1;i<=f;i++){
        if(a[i]>farthest){
            break;
        }
        dfs(i,a[i],f,steps+1);
    }
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        ans=0;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
            for(int j=1;j<=n;j++){
                b[j]=88888888888888888ll;
            }
            memset(road,0,sizeof(road));
            dfs(1,a[1],n,0);
            for(int j=1;j<=n;j++){
                //cout<<road[j]<<' '<<b[j]<<endl;
                if(road[j]==2){
                    ans++;
                }
        }
        cout<<ans<<endl;
    }
   return 0;
}
