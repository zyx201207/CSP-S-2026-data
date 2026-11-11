#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll c,T,a[N],dis[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        ll n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(0<=c&&c<=6){
            vector<int>G[n+5];
            for(int i=1;i<n;i++){
                for(int j=i+1;j<=n;j++){
                    if(a[j]-a[i]<=d)G[i].push_back(j);
                }
            }
            ll ans=0;
            for(int l=1;l<n;l++){
                for(int r=l+1;r<=n;r++){
                    int st=l,k=1;
                    for(int i=l+1;i<=r;i++){
                        if(a[i]-a[st]>d){
                            st=i-1;
                            k++;
                        }
                    }
                    for(int i=l;i<=r;i++)dis[i]=0;
                    queue<int>q;
                    q.push(l);
                    int sum=0;
                    while(q.size()&&sum<=2){
                        int u=q.front();q.pop();
                        for(int i=0;i<G[u].size();i++){
                            int v=G[u][i];
                            if(dis[v]<dis[u]+1&&v!=r&&dis[v]!=0)continue;
                            dis[v]=dis[u]+1;
                            if(v==r){
                                if(dis[v]==k)sum++;
                                else {
                                    while(q.size())q.pop();
                                    break;
                                }
                                break;
                            }
                            q.push(v);
                        }
                    }
                    if(sum==2)ans++;
                }
            }
            cout<<ans<<'\n';
        }else if(c==11||c==12){
            if(n-2*d+1>0)cout<<n-2*d+1<<'\n';
            else cout<<0<<'\n';
        }

    }
    return 0;
}
