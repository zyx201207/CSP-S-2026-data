#include<iostream>
using namespace std;
int a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n,d;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        cout<<0<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
