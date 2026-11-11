#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
ll x[N];
vector<int> G[N];
int cnt[N],f[N];
deque<int> Q;
void DFS(int u,int dep){
    if(dep>f[u]) return ;
    cnt[u]++;
    for(auto v:G[u]){
        DFS(v,dep+1);
    }
    return ;
}
ll ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int id,T;
    cin>>id>>T;
    while(T--){
        int n;
        ll d;
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<=n;i++) G[i].clear();
        if(id==11||id==12){
            if(x[2]-x[1]>d||x[n]-x[1]<=d) cout<<0<<'\n';
            else if(x[2]-x[1]<=d&&x[3]-x[1]>d) cout<<0<<'\n';
            else{
                int pos=1;
                for(int i=2;i<=n;i++){
                    if(x[i]-x[1]>d){
                        pos=i;break;
                    }
                }
                int d=pos-1;
                int pos1=(d-1)+1;
                int pos2=(d-1)*2-1;
                // ans+=(n-pos1);
                ans+=(n-pos2);
                // cout<<pos1<<" "<<pos2<<'\n';
                // for(int i=1;i<d;i++){
                //     if((i+d)%2==0) continue;
                //     cout<<d+i<<" ",ans+=(n-(i+d+1)+1);
                // }
                // cout<<'\n';
                // cout<<"p "<<pos<<" "<<n<<endl;
                cout<<ans<<endl;
            }
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(x[j]-x[i]<=d) G[i].push_back(j);
            }
        }
        // for(int i=1;i<=n;i++) DFS(i);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) f[j]=1e9,cnt[j]=0;
            while(Q.size()) Q.pop_back();
            f[i]=0;
            Q.push_back(i);
            for(int j=i+1;j<=n;j++){
                while(Q.size()&&x[j]-x[Q.front()]>d) Q.pop_front();
                if(Q.size()) f[j]=f[Q.front()]+1;
                else f[j]=1e9;
                while(Q.size()&&f[j]<f[Q.back()]) Q.pop_back();
                Q.push_back(j);
            }
            DFS(i,0);
            // cout<<"F ";
            // for(int j=1;j<=n;j++) cout<<f[j]<<" ";
            // cout<<'\n';
            // cout<<"ct ";
            // for(int j=1;j<=n;j++) cout<<cnt[j]<<" ";
            // cout<<'\n';
            for(int j=1;j<=n;j++){
                if(cnt[j]==2) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}