#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long c,T,n,d,a[N],f[N];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
long long cnt=0;
        for(int i=1;i<=n;i++){
            f[i]=i;
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(abs(a[i]-a[j])<=d){

                              cnt++;
                }
            }
            }

        cout<<cnt<<"\n";
        }
    return 0;
}
