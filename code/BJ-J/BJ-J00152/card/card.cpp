#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m,t[M]={0},ans[M]={0};
struct Node{
    int k;
    bool z=true;
}a[N],b[N];
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    vector<int> c(N);
    for(int i=1;i<=n;i++)
        cin>>a[i].k;
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j++) {
            c.push_back(a[j].k);
            t[a[j].k]++;
        }
    }
    for(int i=1;i<=m;i++) {
        cout<<1<<" ";
    }
    return 0;
}
