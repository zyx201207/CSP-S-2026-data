#include<bits/stdc++.h>
using namespace std;
const int N=505,K=5e5+100;
int a[505][K];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int w[m+1];
    for(long long i=0;i<m;i++)cin>>a[i];
    int k;
    for(int i=0;i<n;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    int x[q],y[q];
    for(int i=0;i<q;i++){
        cin>>x[i]>>y[i];
    }

}
