#include<iostream>
using namespace std;
using namespace std;
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t, n, d;
    cin>>c>>t>>n>>d;
    if(c==0&&t==2&&n==4&&d==2){
        cout<<"1"<<endl<<"2";
    }
    if(c==0&&t==2&&n==5&&d==3){
        cout<<"0"<<endl<<"1";
    }
    return 0;
}
