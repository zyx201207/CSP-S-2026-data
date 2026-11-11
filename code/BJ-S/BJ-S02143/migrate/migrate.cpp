#include<bits/stdc++.h>
using namespace std;
int a[2000001];
int main(){
    freopen("migrate.in",'r';stdin);
    freopen("migrate.out",'w';stdout);
    int c,t,n,d,times;
    times = 0;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
        for(int j=0;j<=n-1;j++){
            if(a[j+1]-a[j]>d){
                times++;
                continue;
            }


        }
        if(times==n){
            cout<<0<<endl;
            times=0;
        }



    }



    return 0;
}
