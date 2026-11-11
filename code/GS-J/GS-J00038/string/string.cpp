#include<iostream>
using namespace std;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    long long n, x=0;
    cin>>n;
    int a[n+1];
    char b[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=n/2;i++){
         if(b[i]!=b[n-i+1]){
             b[i]=b[n-i];
             x+=a[i];
         }
    }
    cout<<x;
    return 0;
}
