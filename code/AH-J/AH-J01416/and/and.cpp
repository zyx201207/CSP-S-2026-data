#include<bits/stdc++.h>
using namespace std;
int a[1000055];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
     int n,m;
     cin>>n>>m;
     for(int i=1;i<=n;i++){
        cin>>a[i];
        int amx=1e5;
        int axt;
        while(1){
            if(amx>a[i])amx=a[i];

        axt=amx;
        if(axt>=amx){
            cout<<amx;
        }
        }

        if(m<=2){
            cout<<2;
        }
             }

    return 0;
}
