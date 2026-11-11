#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long c,n[1000];
    char a[1000];
    cin>>c;
    for(int i=1;i<=c;i++){
        cin>>n[i];
        cin>>a[i];
    }
    if(a[1]==a[2]){
        cout<<"0";
        return 0;
    }
    if(c==2){
        if(n[1]>n[2]){
        cout<<n[2];
        return 0;
        }
    }for(int i=1;i<=c;i++){
        if(c%2==0&&a[i]==a[c/2+i]){
        cout<<c/2;
        }
    }
    return 0;}