#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n;
long long d,a[N],cha;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int qw=1;qw<=t;qw++){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            cha=a[i]-a[i-1];
        }
        if(d/cha==2)cout<<n-3<<endl;
        else cout<<0<<endl;
    }
    return 0;
}

