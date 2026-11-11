#include<iostream>
using namespace std;
long long kskbl[10000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,i,o;
    cin>>n;
    for(i=2;i<=n;i++){
        cin>>kskbl[i];
    }
    cin>>o;
    cout<<o;
}
