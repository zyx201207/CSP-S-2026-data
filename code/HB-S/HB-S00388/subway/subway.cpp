#include<bits/stdc++.h>
#include<cstdlib>
#include<ctime>
using namespace std;
//subway

long long c,n,m,d,q;
int w[500005],a[500005][505],t[500005][505];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=m;i++){
        cin>>a[0][0];
        for(int j=1;j<=a[0][0];j++){
            cin>>a[j][i]>>t[j][i];
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cout<<w[x]+w[y]+rand()%10+1
    }

    return 0;
}
