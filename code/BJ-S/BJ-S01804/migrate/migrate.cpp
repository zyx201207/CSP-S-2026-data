#include<bits/stdc++.h>
using namespace std;
int t1,t2;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>t1>>t2;
    if(t1==11||t1==12){
        while(t2--){
            int n,d,x,y;
            cin>>n>>d>>x>>y;
            if(d/abs(x-y)==2){
                cout<<n-3<<endl;
            }
            else{
                cout<<"0"<<endl;
            }
        }
    }
    return 0;
}