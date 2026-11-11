#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#define ll long long
using namespace std;

inline bool diff(vector<int> &a,vector<int> &b){
    if(a.size() != b.size()){
        return true;
    }
    for(int i = 0;i < a.size();i++){
        if(a[i] != b[b.size() - 1 - i]){
            return true;
        }
    }
    return false;
}

ll fdc(int d,vector<int> &x){
    ll res = 0;
    for(int i = 0;i < x.size();i++){
        for(int j = i + 2;j < x.size();j++){
            vector<int> b1,b2;
            int p1 = i;
            for(int k = i + 1;k <= j;k++){
                if(x[k] - x[p1] > d){
                    b1.push_back(k - 1);
                    p1 = k - 1;
                }
            }
            int p2 = j;
            for(int k = j - 1;k >= i;k--){
                if(x[p2] - x[k] > d){
                    b2.push_back(k + 1);
                    p2 = k + 1;
                }
            }
            if(diff(b1,b2)){
                res++;
            }
        }
    }
    return res;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d %d",&c,&t);
    for(int tt = 0;tt < t;tt++){
        int n,d;
        scanf("%d %d",&n,&d);
        vector<int> x(n);
        for(int i = 0;i < n;i++){
            scanf("%d",&x[i]);
        }
        printf("%lld\n",fdc(d,x));
    }
    return 0;
}
