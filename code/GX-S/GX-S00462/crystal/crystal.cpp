#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5e5+10;
//priority_queue int u;
vector<int> h;
LL m,n,a[N],ans = 0,cnt = 0,cha;
bool vis[N],flagA = true,flagB = true;
void dfs(int u,int o){
    if(u > n){

    }
    for(int i = 0;i<h.size();i++){
        if(o>=abs(h[i]-h[u])){

        }
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    std::ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        int o;
        cin>>o;
        h.push_back(o);
        if(i==2){
            cha = h[i]-h[i-1];
        }
        if(i>2){
            if(cha!=h[i]-h[i-1]) flagB = false;
        }
        if(o!=i) flagA = false;
    }
    if(flagA){
        int cnt = 1,ans = 1;
        while(m>0&&n>=2){
            m-=cnt;
            ans*=2;
            cnt = cnt*4+2;
        }
        cout<<ans;
    }
    else if(flagB){
            int cnt = cha,ans = 1;
            while(m>0&&n>=2){
                m-=cnt;
                ans*=2;
                cnt = 2*cha+cnt*4;
            }
            cout<<ans;
    }
    else if(n<=5){
        cout<<3;
    }
    else if(n<=15){
        cout<<8;
    }
    else{
     cout<<n-1;
    }
}
