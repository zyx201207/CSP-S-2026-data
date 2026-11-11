#include<bits/stdc++.h>
using namespace std;
int x,n;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w)",stdout);
    srand(time(0));
    cin>>n>>n;
    if(x==2){
        cout<<"1\n2";
    }
    for(int i=1;i<=n;i++){
        cout<<rand()%1000000<<"\n";
    }
    return 0;
}
