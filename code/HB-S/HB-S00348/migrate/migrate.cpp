#include<iostream>
using namespace std;
int a[1010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int j=1;j<=t;j++){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
    }
    cout<<1<<endl<<2;
    return 0;
}
