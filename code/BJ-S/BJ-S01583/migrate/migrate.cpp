#include<bits/stdc++.h>
using namespace std;
const int MAXN=2000005;
long long n,d;
long long x[MAXN];
void solve1(){
    cin>>n>>d;
    for (int i=1;i<=n;i++){
        cin>>x[i];
    }
    long long cha=x[n]-x[n-1];
    long long len=d/cha;
    len*=2;
    int ans=n-len+1;
    cout<<ans<<"\n";
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for (int z=1;z<=t;z++){
        solve1();
    }
return 0;
}
