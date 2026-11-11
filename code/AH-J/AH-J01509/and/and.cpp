#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005][40];
int vis[200005];
int light_vis[200005];
long long k;
void turned(int num,long long p){
    int x = 35;
    while(num > 0 && x >= 0){
        long long now = (long long)pow(2,x);
        if(p >= now){
            a[num][x] = 1;
            p -= now;
        }
        x--;
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> k;
        turned(i,k);
    }
    bool flag = 0;
    int cnt = 0;
    int light = 0;
    long long ans = 0;
    for(int i = 35;i>=0;i--){
        if(flag == 0){
            cnt = 0;
            for(int j = 1;j<=n;j++){
                if(a[j][i]){
                    cnt++;
                    vis[j]=1;
                }
            }
            if(cnt < m){
                memset(vis,0,sizeof(vis));
            }else{
                flag = 1;
                light = 1;
                ans += (long long)pow(2,i);
            }
        }else{
            cnt = 0;
            for(int j = 1;j<=n;j++){
                light_vis[j] = vis[j];
            }
            for(int j = 1;j<=n;j++){
                if(a[j][i] && light_vis[j] == light){
                    cnt++;
                    light_vis[j]++;
                }
            }
            if(cnt >= m){
                light++;
                for(int j = 1;j<=n;j++){
                    vis[j] = light_vis[j];
                }
                ans += (long long)pow(2,i);
            }
        }
    }
    cout << ans;
    return 0;
}


