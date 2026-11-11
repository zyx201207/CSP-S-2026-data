#include<bits/stdc++.h>

using namespace std;

int n;
long long cnt = 0;
char s[200010];
int t[200010];
long long ans = 0;
char q;

int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) {
        scanf("%d%c%c",&t[i],&q,&s[i],&q);
        cnt += t[i];
    }
    int x = 1,xa = t[1],y = n,ya = t[n];
    while(cnt > 1){
        if(xa > ya){
            int c = ya;
            if(s[x] != s[y]){
                ans += c;
            }
            cnt = cnt - 2 * c;
            y--;
            ya = t[y];
            xa = t[x] - c;
        }else if(xa == ya){
            int c = ya;
            if(s[x] != s[y]){
                ans += c;
            }
            cnt = cnt - 2 * c;
            x++,y--;
            xa = t[x],ya = t[y];
        }else{
            int c = xa;
            if(s[x] != s[y]){
                ans += c;
            }
            cnt = cnt - 2 * c;
            x++;
            xa = t[x];
            ya = t[y] - c;

        }
    }
    printf("%lld",ans);
    return 0;
}
