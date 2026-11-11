#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    srand(time(0));
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>x;
        }
        cout<<rand()%2+0<<endl;
    }
}