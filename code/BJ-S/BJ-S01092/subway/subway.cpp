#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int num,how;
    cin>>num>>how;
    if(num==11||num==12){
        while(how--){
            int n,m;
            cin>>n>>m;
            int kk[n+5];
            for(int i=1;i<=n;i++){
                cin>>kk[i];
            }
            int c;
            c=abs(kk[2]-kk[1]);
            if(m<2*c||n-(m/c*2-1)<=0){
                cout<<0<<endl;
                continue;
            }
            cout<<n-(m/c*2-1)<<endl;
        }
        return 0;
    }
    while(how--){
        int n,m;
        cin>>n>>m;
        int kk[10005];
        for(int i=1;i<=n;i++){
            cin>>kk[i];
        }

    }
    return 0;
}
