#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],a[505][500005],T,s[100005],e[100005],ki[500005];
int sum;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++){
        cin>>w[i];
    }
    for (int i=1;i<=n;i++){
        cin>>ki[i];
        for (int j=1;j<=ki[i];j++){
            cin>>a[i][j]>>T;
        }
    }
    for (int i=1;i<=q;i++){
        cin>>s[i]>>e[i];
    }
    for (int i=1;i<=q;i++){
        sum=w[s[i]]+w[e[i]]+4*T;
        cout<<sum<<endl;
    }
    return 0;
}