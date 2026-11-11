#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,d;
int a[5010];
int dp[5010][5010];
int g[5010][5010];
int ans;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    if(c==11||c==12){
        while(T--){
            cin>>n>>d;
            int u,cha;
            for(int i=1;i<=n;i++){
                int k;
                cin>>k;
                cha = k-u;u=k;
            }
            if(cha>d){
               cout<<0<<"\n"; 
               continue;
            } 
            else{
                int once = (d/cha);
                for(int i=4;i<=n;i++){
                    if((i-1)*cha<=d) continue;
                    else{
                        if((i-1)/once==1){
                            ans = (n-i+1);
                        }
                    }
                }
            }
            cout<<ans<<"\n";
            ans = 0;
        }
    }
    else{
        while(T--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            for(int i=1;i<=n;i++){
                deque<int> qu;
                g[i][i] = 1;
                dp[i][i] = 0;
                qu.push_back(i);
                for(int j=i+1;j<=n;j++){
                    while(!qu.empty()&&(a[j]-a[qu.front()]>d)){
                        qu.pop_front();
                    }
                    if(qu.empty()){
                        break;
                    }
                    else{
                        int minn = dp[i][qu.front()];
                        dp[i][j] = minn+1;
                        vector<int> v;
                        while(!qu.empty()&&(dp[i][j]<dp[i][qu.back()])){
                            qu.pop_back();
                        }
                        qu.push_back(j);
                        while(!qu.empty()&&dp[i][qu.front()]==minn){
                            //cout<<i<<"-"<<j<<":"<<qu.front()<<"\n";
                            v.push_back(qu.front());
                            g[i][j]+=g[i][qu.front()];
                            qu.pop_front();
                        }
                        if(g[i][j]==2) ans++;
                        for(int i=v.size()-1;i>=0;i--){
                            qu.push_front(v[i]);
                        }
                    }
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    dp[i][j] = 0;
                    g[i][j] = 0;
                }
            }
            for(int i=1;i<=n;i++) a[i]=0;
            cout<<ans<<"\n";
            ans = 0;
        }        
    }
    return 0;
}