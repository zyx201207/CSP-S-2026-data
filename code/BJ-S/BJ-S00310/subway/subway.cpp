#include <bits/stdc++.h>
using namespace std;
long long a[500050],as;
int n;
struct node{
    int x;
    long long z;
}ji[1010][1010];
void dfs(int x,int y,int s,int f,long long tmp){
    if(x > n) return;
    if(s == f){
        as = min(as,tmp);
        return;
    }
    for(int i = x;i <= n;i++){
        while(ji[i][y].x <= f){
            if(!ji[i][y].x) break;
            y++;
            tmp += ji[i][y].z;
        }
        dfs(x+1,1,ji[i][y-1].x,f,tmp);
        y = 1;
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int f;
    cin >> f;
    int m,d,p;
    cin >> n >> m >> d >> p;
    for(int i = 1;i <= m;i++) cin >> a[i];
    for(int i = 1;i <= n;i++){
        int k;
        cin >> k;
        for(int j = 1;j <= k;j++) cin >> ji[i][j].x >> ji[i][j].z;
    }
    while(p--){
        int nx,ny;
        long long tmp = 0;
        cin >> nx >> ny;
        tmp += a[nx] + a[ny];
        as = 1000000010;
        int kx = nx;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= d;j++){
                if(!ji[i][j].x) break;
                if(ji[i][j].x == nx){
                    dfs(i,j,kx,ny,tmp);
                    break;
                }
            }
        }
        cout << as << endl;
    }
    return 0;
}