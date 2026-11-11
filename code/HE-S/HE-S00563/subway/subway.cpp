#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,x[500005],y[500005],sum,ans=5;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>a>>b>>c>>d>>e;
    for(int i=1;i<=c;i++){
        cin>>x[i];
        sum+=x[i];
    }
    ans+=c;
    int m,n,k;
    for(int i=1;i<=b;i++){
        cin>>m;
        sum+=m;
    }
    ans+=b;
    for(int i=1;i<=e;i++){
        cin>>n>>k;
        sum+=n+k;
    }
    ans+=e;
    cout<<sum/ans<<endl;
    return 0;
}
