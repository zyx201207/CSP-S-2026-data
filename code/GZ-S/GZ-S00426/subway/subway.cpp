//GZ-S00426 遵义市第一中学 瞿才涵
#include<bits/stdc++.h>
using namespace std;
struct plan{
    long long start,end;
};

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long c,n,m,d,q,temp;
    cin >>c>>n>>m>>d>>q; 
    long long time_m[m+1]={0};

    plan p[q+1]={0};

    long long w[n+1][d+1]={0};

    for(int i=1;i<=m;i++){
        cin >> time_m[i];
    }

    for(int i=1;i<=n;i++){
        cin >> temp;
        for(int j=1;j<=temp*2;j++){
            cin >> w[i][j];
        }
    }

    for(int i=1;i<=q;i++){
        cin >> p[i].start >> p[i].end;
    }

    return 0;
}
