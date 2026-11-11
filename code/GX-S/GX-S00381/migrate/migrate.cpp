#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,o,n,d,t,f,num=0;
    cin>>c;

    cin>>o;
    //cout<<o;
    //cout<<c+o;
    //cout<<c<<" ";
    for(int i=1;i<=o;i++){
        //cout<<1;
        num=0;
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
        t=a[2]-a[1];
        if(2*t>d){
            cout<<0<<endl;
            //cout<<t<<" "<<d;
            //cout<<1;
            continue;
        }
        for(int j=1;j<=n;j++){
            for(int u=n;u>=j;u--){
                if(u-j==3){
                        if(a[u]-a[j]>0&&a[u]-a[j]>d){
                           num++;
                           //cout<<u<<" "<< j<<" ";
                        }
                        if(a[u]-a[j]<0&&a[u]-a[j]<0-d){
                           num++;
                           //cout<<2;
                        }
                }
            }
        }
        cout<<num<<endl;
    }
    return 0;
}
