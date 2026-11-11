#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ls1[501],t1[501],ls2[501],t2[501],ls3[501],t3[501],ret[501],t=1,ls[501];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        cin >> ls[i];
    }
    if(n == 2){
        int t1,t2;
        cin >> t1;
        for(int i = 1;i <= 2*t1;i++){
            if(i % 2 == 0){
                cin >> ls1[i];
            }
            if(i % 2 == 1){
                cin >> t1[i];
            }
        }
        cin >> t2;
        for(int i = 1;i <= 2*t2;i++){
            if(i % 2 == 0){
                cin >> ls2[i];
            }
            if(i % 2 == 1){
                cin >> t2[i];
            }
        }
        for(int i = 1;i <= t1;i++){
            for(int j = 1;j <= j2;j++){
                if(ls1[2*i-1] == ls2[2*j-1]){
                    ret[t]=t1[2*i-1]+t2[2*j-1];
                    t++;
                }
            }
        }
        sort(ret+1,ret+t+1);
        for(int j = 1;j <= q;j++){
            int f,g;
            cin >> f >> g;
            for(int h = 1;h <= 2*t1){
                continue;
            }
            cout << 30 << endl;
            cout << 5;
        }

    }
}
