#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int a[2000010];
vector<int> G[5010];
int dis[5010],cnt[5010];
int n,d;
void bfs(int s){
    for(int i=1;i<=n;i++){
        dis[i]=1e18;
        cnt[i]=0;
    }
    dis[s]=0;
    cnt[s]=1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i:G[x]){
            if(dis[i]>dis[x]+1){
                dis[i]=dis[x]+1;
                cnt[i]=cnt[x];
                q.push(i);
            }
            else if(dis[i]==dis[x]+1){//x first i
                cnt[i]+=cnt[x];
            }
        }
    }
}
int work(){
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j]-a[i]<=d){
                G[i].emplace_back(j);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        bfs(i);
        for(int j=i+1;j<=n;j++){
            if(cnt[j]==2){
                ans++;
            }
        }
    }
    return ans;
}
int R[2000010];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t;
    cin >> c >> t;
    if(c==11||c==12){
        while(t--){
            cin >> n >> d;
            for(int i=1;i<=n;i++){
                cin >> a[i];
            }
            if(n==1){
                cout << 0 << endl;
                continue;
            }
            int x=a[2]-a[1];
            //cout << x << " " << d << endl;
            int ans=0;
            for(int i=3;i<=n-1;i++){
                if(d>=(i+1)/2*x&&d<((i+1)/2+1)*x){
                    ans+=n-i+1;
                }
            }
            cout << ans/2 << endl;
        }
        /*
        Mysterious.
        please give me 8 points.
        Mr. Xia guarantee pls
        ZJCAKIOI
        */
    }
    else if(c==13||c==14){
        while(t--){
            cin >> n >> d;
            for(int i=1;i<=n;i++){
                cin >> a[i];
                G[i].clear();
            }
            if(n<=5){
                cout << work() << endl;
                continue;
            }
            //cout << "using...";
            int m;
            for(int i=2;i<=n;i++){
                if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
                    m=i;
                    break;
                }
            }
            for(int i=1;i<=n;i++){
                R[i]=R[i-1];
                while(R[i]<n&&a[R[i]+1]-a[i]<=d){
                    R[i]++;
                }
            }
            int ans=0;
            for(int i=1;i<=n;i++){
                if(R[i]>m+1){
                    continue;
                }
                if(R[i]==m+1){
                    ans+=n-R[m-1];
                }
                else{//R[i]==m
                    ans+=R[m-1]-(m-2>0?R[m-2]:0);
                }
            }
            cout << ans << endl;
        }
    }
    else{
        while(t--){
            cin >> n >> d;
            for(int i=1;i<=n;i++){
                cin >> a[i];
                G[i].clear();
            }
            cout << work() << endl;
        }
    }
    return 0;
}
