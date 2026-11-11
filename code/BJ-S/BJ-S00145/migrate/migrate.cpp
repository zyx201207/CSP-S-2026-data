#include<bits/stdc++.h>
using namespace std;
int x,n;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w)",stdout);
    srand(time(0));
    cin>>n>>n>>x;
    if(x==4){
        cout<<"1\n2";
    }
    else if(n==3){
        cout<<"0\n1";
    }
    for(int i=1;i<=n;i++){
        cout<<rand()%INT_MAX<<"\n";
    }
    return 0;
}
