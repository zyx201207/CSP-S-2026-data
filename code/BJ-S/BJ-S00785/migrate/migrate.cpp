#include <iostream>

using namespace std;
int a[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        cout<<0<<endl;
    }
    return 0;
}
