#include<bits/stdc++.h>
using namespace std;
long long w[10000],s[10000][10000],s1[10000][10000],x,y,o=0;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>s[i][0];
        s1[i][0]=s[i][0];
        for(int j=1;j<=s[i][0];j++){
            cin>>s[i][j]>>s1[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        o=0;
        cin>>x>>y;
        o+=w[x];
        o+=w[y];
        cout<<o<<endl;
    }

    return 0;
}
