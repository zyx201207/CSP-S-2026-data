#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n;
        ll d,ans=0;
        cin>>n>>d;
        vector<ll>a(n);
        for(auto &i:a){
            cin>>i;
        }
        if(c!=11&&c!=12){
            vector<vector<int>>edge(n);
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(a[j]-a[i]<=d){
                        edge[i].push_back(j);
                    }
                }
            }
            vector<int>dis(n),cnt(n);
            queue<int>q;
            for(int i=0;i<n;i++){
                fill(dis.begin(),dis.end(),1e+9);
                fill(cnt.begin(),cnt.end(),0);
                dis[i]=0;
                cnt[i]=1;
                q.push(i);
                while(!q.empty()){
                    for(auto i:edge[q.front()]){
                        if(dis[i]==1e+9){
                            dis[i]=dis[q.front()]+1;
                            q.push(i);
                            cnt[i]=cnt[q.front()];
                        }
                        else if(dis[i]==dis[q.front()]+1){
                            cnt[i]+=cnt[q.front()];
                        }
                    }
                    q.pop();
                }
                for(int j=0;j<n;j++){
                    if(cnt[j]==2){
                        ans++;
                    }
                }
            }
            cout<<ans<<'\n';
        }
        else if(n<=3){
            cout<<0<<'\n';
        }
        else{
            ll dis=a[1]-a[0];
            ll t=d/dis;
            if(t<=1){
                cout<<0<<endl;
            }
            else{
                cout<<max(0ll,n-2*t+1)<<'\n';
            }
        }
    }
    return 0;
}
