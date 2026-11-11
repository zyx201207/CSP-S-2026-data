#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long c[500005];
long long mem[500005];
stack <long long> desk;
long long re[300005];

int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i = 1; i <= n; i ++) {
        cin >> c[i];
    }
    for(long long g = 1; g <= n; g ++) {
        for(long long i = g; i <= n; i ++) {
            if(!mem[c[i]]) {
                desk.push(c[i]);
                mem[c[i]] = 1;
            }
            else {
                while(mem[c[i]]) {
                    mem[desk.top()] = 0;
                    desk.pop();
                }
                desk.push(c[i]);
                mem[c[i]] = 1;
            }
        }
        bool visited[300005] = {};
        while(!desk.empty()) {
            long long cur = desk.top();
            desk.pop();
            if(visited[cur]) continue;
            re[cur]++;
            visited[cur] = 1;
        }
        memset(mem,0,sizeof(mem));
    }
    for(int i = 1; i <= m; i ++) {
        printf("%lld ",re[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
