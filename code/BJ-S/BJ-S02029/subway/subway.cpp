#include<bits/stdc++.h>
using namespace std;
long long a[500005],t[500005],ans;
long long w[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        long long s;
        cin>>s;
        for(int j=1;j<=s;j++){
            cin>>a[j]>>t[j];
        }
    }
    for(int i=1;i<=q;i++){
        long long x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]<<endl;
    }
    return 0;
}
