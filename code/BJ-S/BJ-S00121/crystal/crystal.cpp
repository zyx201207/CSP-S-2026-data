#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+11;
using ll = long long;
ll a[N];
ll b[N][2];
int n;
int id2;
ll mx;
ll mn;
ll c[N];
bool vis[N];
bool flag = true;

bool cmp(ll a,ll b){
    return a<b;
}

int dfs(int id,ll m,int ans){
    if(m<=0||id<=0||id>n||ans>=n){
        return ans;
    }

    int s = 0,x = 0;
 //   cout << 1 << endl;
    if(!vis[id]){
        vis[id] = true;
        s = dfs(id-1,m-((b[id][1]-b[id-1][1])*b[id-1][0]),ans);
        x = dfs(id+1,m-((b[id+1][1]-b[id][1])*b[id][0]),ans);
        vis[id] = false;
       // cout << max(s,x)+b[id][0] << " ";
        return max(s,x)+b[id][0];
    }
    else{
        s = dfs(id-1,m-((b[id][1]-b[id-1][1])*b[id-1][0]),ans);
        x = dfs(id+1,m-((b[id+1][1]-b[id][1])*b[id][0]),ans);
   //     cout << max(s,x) << " ";
        return max(s,x);
    }


}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll m;   cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];

    sort(a+1,a+n+1,cmp);
    mn = abs(a[1]);
    mx = a[1];
    int id = 1,mnn = 1;
    b[id][1] = a[1];
    for(int i=1;i<=n;i++){
        if(b[id][1]!=a[i]) b[++id][1] = a[i];
        b[id][0]++;
        if(mn>abs(a[i])){
            mn = abs(a[i]),mnn = i;
        }
        mx = max(mx,a[i]);
        vis[i] = false;
    }
    //for(int i=1;i<=id;i++) cout << b[i][0] << " " << b[i][1] << endl;
   // cout << mn <<" " << mnn << endl;
    cout << dfs(mnn,m,0);
    return 0;
}
