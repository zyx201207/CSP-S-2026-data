#include<iostream>
#include<bits/c++allocator.h>
using namespace std;
long long D,q,i,n,j,z;
char x;
string a;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(i=0;i<n;i++){
    cin>>z>>x;
    for(j=0;j<z;j++){
        a[q]=x;
        //cout<<a[q]<<endl;
        q++;
    }
}
//cout<<q;
//cout<<a[q/2]<<endl;
for(i=0;i<q/2;i++){
    if(a[i]!=a[q-i-1]){
        //cout<<a[q-i-1];
        D++;
    }
}
cout<<D;
return 0;
}
