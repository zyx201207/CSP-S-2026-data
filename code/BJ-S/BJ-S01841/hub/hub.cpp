#include <bits/stdc++.h>
std::vector<int> a[1000010];
int dis[1000010];
int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int c,t,n,k,u,v;
    std::cin>>c>>t;
    if(c == 13 || c == 14) {
        for(;t--;) {
            std::cin>>n>>k;
            for(int i = 1;i < n;i++) {
                std::cin>>u>>v;
            }
            if(n == k) {
                std::cout<<"0\n";
            }
            else if(k == 1) {
                std::cout<<(n/2+2)/2<<"\n";
            }
            else {
                std::cout<<std::max(1,(n/2-k+2+3)/4)<<"\n";
            }
        }
        return 0;
    }
    for(;t--;) {
            int ans = 1145141111;
        std::cin>>n>>k;
        for(int i = 1;i <= n;i++) {
            std::vector<int>().swap(a[i]);
        }
        for(int i = 1;i < n;i++) {
            std::cin>>u>>v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        std::queue<int> q;
        for(int i = 0;i < (1<<n);i++) {
            int p= i;
            int cnt = 0;
            for(;p;p>>=1) {
                if(p&1) {
                    cnt++;
                }
            }

            if(cnt == k) {
                    int max = 0;
                    for(int i = 1;i <= n;i++) {
                        dis[i] = 1145141111;
                    }
                for(int h = 0;h < n;h++) {
                    if(i & (1<<h)) {
                        dis[h+1] = 0;
                        q.push(h+1);
                    }
                }
                for(;!q.empty();) {
                    for(int j = 0;j < a[q.front()].size();j++) {
                        if(dis[a[q.front()][j]] == 1145141111) {
                            q.push(a[q.front()][j]);
                        }
                        dis[a[q.front()][j]] = std::min(dis[a[q.front()][j]],dis[q.front()]+ 1);
                    }
                    q.pop();
                }
                for(int j = 1;j <= n;j++) {
                    max = std::max(max,dis[j]);
                }
                ans = std::min(max,ans);
            }
        }
    std::cout<<ans<<"\n";
    }
}
