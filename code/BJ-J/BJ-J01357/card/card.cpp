#include <iostream>
#include <algorithm>
using namespace std;

long long maxx(long long a,long long b){

    if(a<b){
        return b;
    }
    return a;
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long m,n;
    cin>>n>>m;
    int a[500000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int co=1;

    for(int i=0;i<n;i++){
        for(int j=0;i<n;i++){
            cout<<co;
        }
    }
}