#include<bits/stdc++.h>
using namespace std;
int ans=0;
long long int a[10000001];
char c[1000000001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    int cnt;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    if(n==1)cout<<0;
    else if(n==2){
        if(c[1]==c[2])cout<<0;
        else if(a[1]>a[2])cout<<a[2];
        else cout<<c[1];
    }
    else if(n==3){
        if(a[2]>a[1]+a[3])cout<<a[1]+a[3];
        else if(a[2]=a[1]+a[3]){
            if(a[1]>a[3])cout<<a[1];
            else cout<<a[3];
        }
        else if(a[1]>a[3])cout<<a[1];
        else cout<<a[3];
    }
    else{//他妈的不会写 超!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    }
    return 0;
}
