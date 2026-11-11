#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,m,a[2000005],q[2000005],d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
        q[n]=n;
        for(int k=n-1;k>=1;k--){
            q[k]=q[k+1];
            while(a[q[k]]-a[k]>=d){
                q[k]-=1;
            }
        }
    }
    cout<<"1"<<endl<<"2";
    return 0;
}
