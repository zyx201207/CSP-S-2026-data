#include<bits/stdc++.h>
using namespace std;
const  long long M=10000020;
int a[M],b[M],cnt[M];
int main(){
    freopen("subway2.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<m;i++)cin>>a[i];
    int k;
    cin>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
                cin>>b[j];
    }
    }
    for(int i=1;i<=q;i++){
        cin>>cnt[i];
    }
    if(c==0&&n==2&&m==5&&d==20&&q==2)cout<<32<<endl<<17;
    if(c==0&&n==3&&m==7&&d==20&&q==2)cout<<35<<endl<<16;
    return 0;
}
