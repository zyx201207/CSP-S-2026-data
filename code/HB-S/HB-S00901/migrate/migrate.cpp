#include<bits/stdc++.h>
using namespace std;
int a[2000001];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int m,n,c,b;
    cin>>m>>n;
    for(int i=0;i<n;++i){
        cin>>c>>b;
        if(c<=3||b==1){
            cout<<"0"<<'\n';
            continue;
        }
        for(int j=0;j<c;++j){
            cin>>a[j];
            if(a[j]-a[j-1]>b){
                c=j;
                break;
            }
        }
        if(c<=3){
            cout<<"0"<<'\n';
            continue;
        }
        if(a[1]-a[0]<b&&b/2<a[1]-a[0]){
            cout<<"0"<<'\n';
        }
        else{
            cout<<c-3<<'\n';
        }
    }
    return 0;
}
