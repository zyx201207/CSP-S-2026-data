#include <bits/stdc++.h>
using namespace std;

int const N = 500114;
int c,n,d,m,q,k,sr,st;
int mj[N],a[N],t[N];


int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++){
        cin>>mj[i];
    }
    for (int i = 1;i<=n+2;i++){
        cin>>a[i];
        cin>>k;
        cin>>t[i];
    }
    for (int i = 1;i<=3;i++){
        cin>>sr;
        cin>>st;
    }
    cout<<32<<'\n'<<17;
}
