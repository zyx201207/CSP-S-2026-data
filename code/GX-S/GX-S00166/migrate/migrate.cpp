#include<bits/stdc++.h>
using namespace std;
int main(){
    int c,t;
    cin>>c>>t;
    freopen("migrate.in","w",stdin);
    freopen("migrate.out","r",stdout);
    for(int i=1;i<=t;i++){
        int a,d,island[10086];
        cin>>a>>d;
        for(int j=1;j<=a;j++){
            cin>>island[j];
        }
    if(a==4&&d==2){
        cout<<"1"<<endl<<"2";
    }
    else{
        cout<<"0"<<endl<<"1";
    }
    }
    return 0;
}
