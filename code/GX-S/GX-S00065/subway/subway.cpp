#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[100005],x[100005],y[100005];
vector<int>a[100005],t[100005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=q;i++){
        cin>>k[i];
        int num;
        for(int j=1,num;j<=k[i];j++) cin>>a[i][k[i]]>>t[i][k[i]];
        for(int r=1;r<=q;r++) cin>>x[r]>>y[r];
    }
    return 0;
}
