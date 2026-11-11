#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
stack<pair<int,int> > pq;//time val
int ans[N];
int l,r;
vector<pair<int,int> > v;
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++) {
        while(!pq.empty()) pq.pop();
        for(int j=i;j<=n;j++) {
            v.clear();
            if(!pq.empty()) {
                while(!pq.empty() && pq.top().second!=a[j]) {
                    v.push_back(pq.top());
                    pq.pop();
                }
                if(!pq.empty()) {
                    pq.pop();
                } else {
                    reverse(v.begin(),v.end());
                    for(const auto &x:v) {
                        pq.push(x);
                    }
                }
            }
            pq.push({j,a[j]});
        }
        while(!pq.empty()) {
            ans[pq.top().second]++;
            pq.pop();
        }
    }
    for(int i=1;i<=m;i++) {
        printf("%d ",ans[i]);
    }
    return 0;
}
