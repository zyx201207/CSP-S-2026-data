#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,ansk=0,n,d;
    cin>>c>>t;
    for(int i=0;i<t;i++){
        cin>>n>>d;
        vector<int>x(n+1,0);
        if(n<4){
            cout<<0<<endl;
            continue;
        }
        for(int j=1;j<=n;j++){
            cin>>x[j];
            if(abs(x[j]-x[1])>d){
                n=j-1;
                break;
            }
        }if(abs(x[n]-x[1])==d){
            cout<<0<<endl;
            continue;
        }cout<<ansk<<endl;
        ansk=0;
    }
    return 0;
}
