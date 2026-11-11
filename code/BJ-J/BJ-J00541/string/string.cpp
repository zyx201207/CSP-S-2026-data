#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,z,j=0,a[200050];
    string c;
    char m;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
        m=c[1];
        if(c[i]==m){
            j++;
        }}
    if(j==n){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        z+=a[i];}
        cout<<(z/2);
    return 0;}
