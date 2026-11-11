#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,p,ja,jt;
    long long w[500005];
    long long a[500005][500005];
    long long t[500005][500005];
    long long x[500005];
    long long y[500005];
    long long k;
    cin>>c>>n>>m>>d>>p;
    for(long long i=1;i<=m;i++){
        cin>>w[i];
    }
    for(long long i=1;i<=n;i++){
        cin>>k;
        for(long long j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
            if(a[1][j]==a[2][j]){
                ja=a[1][j];
                jt=t[1][j]+t[2][j];
            }
        }
    }
    for(long long i=1;i<=p;i++){
        cin>>x[i]>>y[i];
        for(int j=1;j<=k;j++){
            if(y[i]==a[2][j]){
                cout<<w[1]+t[1][1]+jt+t[2][j]+w[y[i]];
            }
        }
    }

}
