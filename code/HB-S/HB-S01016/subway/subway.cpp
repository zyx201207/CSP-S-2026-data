#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int c,n,m,d,q,l,r,ans;
int w[N];
struct {
    int v,t;
} a[N];
int check() {
    for(int i=1;i<=n;i++) {
        
    }
}
int main () {
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        for(int j=1;j<=x;j++) {
            cin>>a[j].v>>a[j].t;
        }
    }
    for(int i=1;i<=q;i++) {
        cin>>l>>r;
        ans+=w[l]+w[r];
        check();
    }
    return 0;
}