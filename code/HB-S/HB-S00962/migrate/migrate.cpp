#include<bits/stdc++.h>
using namespace std;
typedef long long lld;

const int MAXN = 2e6+7;

int c, t;
lld a[MAXN];

void init(){
    memset(a, 0, sizeof a);
}

int main(){
    scanf("%d%d", &c, &t);
    while(t--){
        int n, d;
        scanf("%d", &n, &d);
        for(int i = 1; i<=n; i++){
            scanf("%lld", a+i);
        }
    }
}