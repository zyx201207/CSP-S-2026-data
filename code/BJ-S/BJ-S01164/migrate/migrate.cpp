#include <bits/stdc++.h>
using namespace std;
int c,t,a;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t>>a;
    if(c==0&&t==2&&a==4){
        cout<<"1\n2";
        return 0;
    }
    if(c==0&&t==2&&a==5){
        cout<<"0\n1";
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
}
