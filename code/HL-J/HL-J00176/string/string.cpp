#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef pair<int,char> PI;
typedef long long LL;
int n;
PI a[N];
list<PI> ls;
LL ans=0;
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> a[i].first >> a[i].second;
        ls.push_back(a[i]);
    }
    while(ls.size() > 1) {
        PI p=ls.front();
        PI q=ls.back();
        ls.pop_front();
        ls.pop_back();
        if(p.first==q.first) {
            if(p.second!=q.second) ans+=p.first;
        } else if(p.first<q.first) {
            q.first-=p.first;
            ls.push_back(q);
            if(p.second!=q.second) ans+=p.first;
        } else {
            p.first-=q.first;
            ls.push_front(p);
            if(p.second!=q.second) ans+=q.first;
        }
    }
    cout << ans << endl;
    return 0;
}
