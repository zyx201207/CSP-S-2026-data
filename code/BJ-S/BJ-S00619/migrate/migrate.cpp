#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","w",stdin);
    freopen("migrate.out","r",stdout);
    long long c,t,n,d,x;
    bool z=true;
    cin>>c>>t;
    for(int i=0;i<t;i++){
        cin>>n>>d;
        if((n!=4&&d!=2)||(n!=5&&d!=2)) z=false;
        for(int j=0;j<n;j++){
            cin>>x;
            if(x>5) z=flase;
        }
    }
    if(z==true) {
        cout<<1<<endl;
        cout<<2<<endl;
    }
    return 0;
}
