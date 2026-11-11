#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
const int INF=1e6+5;
int c,t;
int n,d;
int pos[N];
int ans;
int tong[INF];
int bg;
int ed;
int cnt;
int minn=0x3f3f3f3f;
int num;
void dfs(int x){
    if(x==ed){
        //cout << num << " " << cnt << endl;
        if(num<minn){
            minn=num;
            cnt=0;
        }
        cnt++;
        //cout << cnt << endl;
        return ;
    }
    for(int i=1;i<=d&&x+i<=n;i++){
        int nx=x+i;
        if(tong[nx]){
            num++;
            dfs(nx);
            num--;
        }
    }
    return ;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i=1;i<=n;i++){
            cin >> pos[i];
            tong[pos[i]]=1;
        }
        for(int i=1;i<=n-3;i++){
            for(int j=i+3;j<=n;j++){
                bg=pos[i];
                ed=pos[j];
                dfs(bg);
                //cout << endl << cnt << endl;
                if(cnt==2){
                    ans++;
                }
                num=0;
                cnt=0;
                minn=0x3f3f3f3f;
            }
        }
        cout << ans << endl;
        ans=0;
    }
    return 0;
}
