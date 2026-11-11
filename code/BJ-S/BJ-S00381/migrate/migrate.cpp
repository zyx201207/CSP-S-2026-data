#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t){
        int n;
        long long d,x[200006];
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        cout<<x[1]<<endl;
        t--;
    }
    return 0;
}
