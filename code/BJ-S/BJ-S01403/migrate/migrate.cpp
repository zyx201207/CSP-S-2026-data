#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int cha=a[2]-a[1];
        if(d<=cha){
            cout<<0<<endl;
        }
        else{
            int cont=d/cha;
            int maxx=cont*2-1;
            int len=(cont*2-1-cont);
            int tot=n-1-cont;
            cout<<tot*len<<endl;
        }
    }

    return 0;
}

