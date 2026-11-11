#include <bits/stdc++.h>
using namespace std;
// #define int long long
int c,q,n,k,ans;
struct tree{
    vector<int> sons;
    int fa,dep;
    //int siz,sum;
}num[1000005];
//int pp[4005][2][1005][2]; // 第i个数第几个连通块永乐几个城市我用没用的最大值
int dp[1000005][30];
map<int,int> mp;
tree empt;
void init(){
    for(int i=1;i<=n;i++){
        num[i]=empt;
        for(int j=0;j<=30;j++){
            dp[i][j]=0;
        }
    }
    n=0,k=0;ans=1e9;
    mp.clear();
}
// signed main(){
void dfs(int x,int f){
    for(int i=1;i<=30;i++){
        dp[x][i]=dp[dp[x][i-1]][i-1];
    }
    for(int i=0;i<num[x].sons.size();i++){
        int son=num[x].sons[i];
        if(son!=f){
            dp[son][0]=x;
            num[son].fa=x;
            num[son].dep=num[x].dep+1;
            dfs(son,x);
            //num[x].siz+=num[son].siz;
            //num[x].sum+=num[son].sum+num[son].siz;
        }
    }
    //num[x].siz++;
    //num[x].sum+=num[x].dep;
    return ;
}
int lca(int a,int b){
    if(num[a].dep<num[b].dep)
        swap(a,b);
    int diff=num[a].dep-num[b].dep;
    for(int i=30;i>=0;i--){
        if(diff & (1<<i)){
            a=dp[a][i];
        }
    }
    if(a==b)
        return a;
    for(int i=30;i>=0;i--){
        if(num[dp[a][i]].dep!=num[dp[b][i]].dep){
            a=dp[a][i];
            b=dp[b][i];
        }
    }
    return dp[a][0];
}
void dfs1(int x){
    mp[x]=0;
    if(mp[num[x].fa]){
        dfs1(num[x].fa);
    }
    for(int i=0;i<num[x].sons.size();i++){
        int son=num[x].sons[i];
        if(mp[son]){
            dfs1(son);
        }
    }
    return ;
}
//void dfsdp(int x,int f){
    //return ;
    //for(int i=0;i<num[x].sons.size();i++){
        //int son=num[x].sons[i];
        //if(son!=f){
           // dfsdp(son,x);
            //for(int j=1;j<=k;j++){
                //dp[x][0][j][1]=min(dp[x][0][j][1],min(dp[x][0][j-1][1],num[son].sum+num[son].siz));
                //dp[x][1][j][1]=min(dp[x][1][j][1],min(dp[x][1][j-1][1],dp[x][0][j][0]));
                //dp[x][1][j][1]=min(dp[x][1][j][1],min(dp[x][1][j-1][1],dp[x][0][j][0]));
            //}
       // }
    //}
    //num[x].siz++;
    //num[x].sum+=num[x].dep;
//}
void solve(){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        num[a].sons.push_back(b);
        num[b].sons.push_back(a);
    }
    num[1].dep=0;
    dfs(1,0);
    if(1){
        for(int i=0;i<(1<<n);i++){
            vector<int> nums;
            mp.clear();
            int j=i;
            int cnt=1;
            while(j){
                cnt++;
                if(j & 1){
                    nums.push_back(cnt);
                    mp[cnt]=1;
                }
                j>>=1;
            }
            if(nums.size()!=k)
                continue;
            int lian=1;
            dfs1(nums[0]);
            for(int j=0;j<nums.size();j++){
                if(mp[nums[j]]){
                    dfs1(nums[j]);
                    lian++;
                }
            }
            if(lian>2)
                continue;
            //cout<<"!";
            int mx=0;
            for(int j=1;j<=n;j++){
                int mn=1e9;
                for(int k=0;k<nums.size();k++){
                    int tmp=lca(j,nums[k]);
                    mn=min(mn,num[j].dep+num[nums[k]].dep-2*num[tmp].dep);
                }
                mx=max(mx,mn);
            }
            ans=min(ans,mx);
        }
        cout<<ans<<'\n';
        return ;
    }
    //else{
        //dfsdp(1,0);
    //}
    return ;
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>q;
    while(q--){
        init();
        solve();
    }
    return 0;
}
