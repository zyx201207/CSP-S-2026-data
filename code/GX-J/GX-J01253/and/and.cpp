#include<iostream>
#include<bits/c++allocator.h>
using namespace std;
int n,m,i,j,a[110000],b[110000];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(i=0;i<n;i++){
    cin>>a[i];
}
    for(i=0;i<n;i++){
        for(j=i;j<m;j++){
            if(a[j]<=a[i]){
                b[i]=a[j];
            }
        }}
    for(i=0;i<n;i++){
        if(b[i]<b[i+1]){
            b[i]=b[i+1];
        }else{
            b[i+1]=b[i];
        }
    }
    cout<<b[0];
return 0;
}
