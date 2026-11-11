#include<bits/stdc++.h>
using namespace std;
const int N=
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int w[m+5];
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int k;
    cin>>k;
    int a[k+5],t[k+5];
    long long sum=0,cnt=0;
    for(int i=1;i<=m;i++){
        sum+=w[i];
    }
    for(int i=1;i<=k;i++){
        cnt+=a[i]+t[i]-w[i];
    }
    cout<<sum<<"\n"<<cnt;
    return 0;
}
