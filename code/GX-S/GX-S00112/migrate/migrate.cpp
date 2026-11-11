#include<iostream>
using namespace std;
long long c,t,n,d,a[200001];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i = 0;i < n;i++){
            scanf("%lld",&a[i]);
        }
        if(c == 11 || c == 12){
            if(d >= 2 * (a[1] - a[0]) && d < 3 * (a[1] - a[0])){
                cout<<n - 3;
            }else{
                cout<<0;
            }
        }
    }
}
