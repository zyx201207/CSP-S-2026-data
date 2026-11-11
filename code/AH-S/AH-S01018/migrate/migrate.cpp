#include<bits/stdc++.h>
using namespace std;
const int N=2e6+1;
long long c,t,n,d,a[N],minn=0x3f3f3f3f,ans;
map<long long,long long>mp;
void dfs(long long u,long long v,long long t){
    if(t>minn){
        return;
    }
    if(u==v){
        if(minn>t)
            minn=t;
        mp[t]++;
        return;
    }
    for(long long f=1;f<=d&&u+f<=v;f++){
        for(int i=n;i>=1;i--){
            if(u+f==a[i]){
                dfs(u+f,v,t+1);
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int u=1;u<=n;u++){
            for(int v=u+1;v<=n;v++){
                minn=0x3f3f3f3f;
                mp.clear();
                dfs(a[u],a[v],t);
                //cout<<a[u]<<" "<<a[v]<<" "<<minn<<"\n";
                if(mp[minn]==2){
                    //cout<<a[u]<<" "<<a[v]<<"\n";
                    //cout<<minn<<"\n";
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
        ans=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
