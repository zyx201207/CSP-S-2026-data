#include <bits/stdc++.h>
using namespace std;
bool tw[200005][32],unuse[200005];
int p[32] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912};
void turn(int a,int f){
    int c = 0;
    while(a){
        tw[f][c] = a % 2;
        a/=2;
        c++;
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans = 0;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        turn(x,i);
    }
    for(int i = 29;i >= 0;i--){
        int c = 0;
        for(int j = 0;j < n;j++){
            if(unuse[j]){
                continue;
            }
            if(tw[j][i]){
                c++;
            }
        }
        if(c >= m){
            ans+=p[i];
            for(int j = 0;j < n;j++){
                if(unuse[j]){
                    continue;
                }
                if(tw[j][i] == 0){
                    unuse[j] = 1;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
