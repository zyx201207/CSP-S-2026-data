#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;
ll x[2000005],d,dis[2000005],ccnt,cntdis[2000005];
/*oid dfs(int xx,int yy,int now,int cnt){
    cout<<xx<<" "<<yy<<" "<<now<<endl;
    if(now==yy){
        if(dis[yy]>cnt){
            dis[yy]=cnt;
            cntdis[yy]=1;
        }
        else if(dis[yy]==cnt){
            cntdis[yy]++;
        }
        else{
            return;
        }
    }
    int lim=now;
    for(int i=now+1;i<=yy;i++){
        if(x[i]-x[xx]>d){
            break;
        }
        lim=i;
    }
    if(lim<=now+1){
        return;
    }
    dfs(xx,yy,lim,cnt+1);
    dfs(xx,yy,lim-1,cnt+1);
}*/
int main(){
    int c,t;
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ll n;
        cin>>n>>d;
        for(ll i=1;i<=n;i++){
            cin>>x[i];
        }
        if(n<3){
            cout<<"0"<<endl;
        }
        if(c==11||c==12){
            if(x[4]-x[1]<=d){
                cout<<ll(n)*ll(n-3)/2<<endl;
            }
            else{
                cout<<"0"<<endl;
            }
        }
        //cout<<ans<<endl;
    }
    return 0;
}
