#include<bits/stdc++.h>
#define long long ll
using namespace std;
int a[200010],dp[200010],sum=0,m;
bitset<31> s[200010];
bitset<200010> ton[40];
vector<int> to[40];
int t[40];
map<int,int> vis;
void dfs(int i){
    cout<<i<<endl;
    if(sum!=0){
        int cnt=0;
        for(int j=0;j<to[i].size();j++){
            int dj=to[i][j];
            if(vis[dj]){
                cnt++;
            }
        }
        if(cnt<m){
            return ;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,maxn=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(m==1){
        cout<<maxn<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        s[i]=a[i];
        for(int j=30;j>=0;j--){
            if(s[i][j]==1){
                ton[j][i]=1;
                to[j].push_back(i);
                t[j]++;
            }
        }
    }
    for(int i=30;i>=0;i--){
        if(t[i]>=m){
            map<int,int> is;
            int cnt=0;
            if(sum!=0){
                for(auto j:to[i]){
                    if(vis[j]){
                        is[j]=true;
                        cnt++;
                    }
                }
                if(cnt<m){
                    continue;
                }
                for(int i=1;i<=n;i++){
                    vis[i]=vis[i]&is[i];
                }
            }
            if(sum==0){
                for(auto j:to[i]){
                    vis[j]=true;
                }
            }
            sum+=1<<i;
        }
    }
    cout<<sum<<"\n";
    return 0;
}
