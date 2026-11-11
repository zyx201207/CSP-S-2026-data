#include<iostream>
using namespace std;
const int N=5e5+7;
int c,T,n;
long long a[N],d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    for(int i=1;i<=T;i++){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        int dt=a[2]-a[1],ans=0;
        if(2*dt<=d)ans=n-2+n-3;
        cout<<ans<<'\n';
    }
}
