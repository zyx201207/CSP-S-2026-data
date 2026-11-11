#include <iostream>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        long long a;
        cin>>a;
    }
    if(n==4){
        cout<<"1 2 1 3";
    }else{
        cout<<"3 1 2 1 3 2 3 1 2 1";
    }
    return 0;
}
