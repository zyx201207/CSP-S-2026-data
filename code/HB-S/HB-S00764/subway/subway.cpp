#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct node{
    int a,t;
}e[500500];
int k;
long long w[500500];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        cin>>e[i].a>>e[i].t;
    }
    for(int i=1;i<=q;i++){
        int xr,yr;
        cin>>xr>>yr;
    }

    return 0;
}
