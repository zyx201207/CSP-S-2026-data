#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+9;
ll c,t,n,d,a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++)
                cin>>a[i];
            ll di=a[2]-a[1];
            if(di*2>d){
                cout<<"0\n";
                continue;
            }
            else cout<<(n-a[1])/2<<endl;
        }
    }else{
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++)
                cin>>a[i];
            ll di=a[2]-a[1];
            if(di>=d){
                cout<<"0\n";
                continue;
            }
            else cout<<"1\n";
        }
    }
    return 0;
}
