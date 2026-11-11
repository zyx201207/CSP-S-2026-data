#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,m,n,d,q,k[500],w[10086];
    int a[12121][21212];
    bool visited[1005];
    int stmin=0;
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>k[i];
        for(int j=1;j<=n;j++){
            cin>>a[j][i];
        }
    }
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    return 0;
}