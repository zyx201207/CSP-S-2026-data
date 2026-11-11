#include <iostream>
using namespace std;

const int maxn = 1e5 + 50;
long long c, t, n, d;
long long x[maxn];

bool chazhao(long long f){//查找这个数是否存在于数组中
    for(int i = 1;i <= n;i ++){
        if(x[i] == f) return true;
    }
    return false;
}
long long two(long long p,long long ii,long long q,long long jj){//返回这两个岛屿之间的最短路数量
    if(jj - ii > d && jj - ii < 2 * d){
        int tmp = (q-p)/2;
        if(tmp % 2 == 0 && chazhao(x[ii]+d) && chazhao(x[jj]-d)){
            return 1;
        }
        else if(chazhao(x[ii]+d) && chazhao(x[jj]-d)){
            return 2;
        }
    }else{
        return 1;
    }

}

int main(){

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    cin >> c >> t;

    while(t --){
        cin >> n >> d;
        for(int i = 1;i <= n;i ++) {
            cin >> x[i];
        }
        int cnt = 0;

        for(int i = 1;i<= n-3;i ++){
            for(int j = i + 3;j <= n;j ++){
                if(two(x[i],i,x[j],j) == 2){
                    //cout << i << " " << j << endl;
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}//migrate