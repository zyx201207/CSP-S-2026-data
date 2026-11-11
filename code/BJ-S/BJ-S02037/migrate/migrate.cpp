#include<bits/stdc++.h>
using namespace std;

int c,t;
long long n[200005],d[200005];
int x[200005];

int main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n[i]>>d[i];
        for(int j=1;j<=n[i];j++){
            cin>>x[j];
        }
        if(n[i]<=3){
            cout<<0;
            continue;
        }
    }

    return 0;
}
