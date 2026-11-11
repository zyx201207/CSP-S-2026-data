#include<iostream>
#include<queue>
using namespace std;
int n,m,a[500001],lt[500001],id[500001],sz[500001],rs[300001];
vector<int> e[500002];
void ds(int x) {
    sz[x]=1;
    for(int y:e[x]) {
        ds(y);
        sz[x]+=sz[y];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>=1;i--) {
        if(!lt[a[i]]) {
            id[i]=a[i];
            e[i+1].push_back(i);
        }
        else e[lt[a[i]]].push_back(i);
        lt[a[i]]=i;
    }
    ds(n);
    for(int i=1;i<=n;i++) rs[id[i]]+=sz[i];
    for(int i=1;i<=m;i++) cout<<rs[i]<<" ";
    cout<<"\n";
    return 0;
}
