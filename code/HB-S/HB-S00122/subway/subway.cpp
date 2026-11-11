#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[501];
struct node{
    int x;
    unordered_map <int,int> um;
}way[500001];
int main(){
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++) cin>>w[i];
    for (int i=1;i<=n;i++){
        int k;
        cin>>k;
        way[i].x=k;
        for (int j=1;j<=k;j++){
            int a,b;
            cin>>a>>b;
            way[i].um[a]=b;
        }
    }
    for (int i=1;i<=q;i++){
        int f,t;
        cin>>f>>t;
    }
    return 0;
}
