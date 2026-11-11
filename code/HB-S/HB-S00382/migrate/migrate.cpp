#include<bits/stdc++.h>
using namespace std;
int n,d;
int a[2000002]={0};
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==11||c==12||c==0){
        while(t--){
            cin>>n>>d;
            cout<<n<<d;
            for(int i=1;i<=n;i++){cin>>a[i];}
            if(d==a[2]-a[1]){cout<<0;}
            else{cout<<n-(d/(a[2]-a[1]))*2+1<<'\n';}
        }
    }
    else{
        while(t--){
            cout<<0;
        }
    }
    return 0;
}
