#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,m;
    int a[1000000];
    char b[1000000];
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    if(n==1){
        cout<<0;
    }
    if(n==2){
        if(b[0]!=b[1]){
            cout<<min(a[0],a[1]);
        }
        else{
            cout<<0;
        }
    }
return 0;
}
