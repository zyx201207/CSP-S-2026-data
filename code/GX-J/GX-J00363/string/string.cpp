#include<bits/stdc++.h>
using namespace std;
int n,a[]={},num=0,x=0;
char c[]={};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=0;i<n;i++){
        if(c[i]!=c[i+1])x=1;
        }
    for(int i=0;i<n;i++)num+=a[i];
    if(x)cout<<num/4;
    else cout<<0;
}
