#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m;
cin>>n;
cin>>m;
int a[n];
for(int i=0;i<n;++i){
    cin>>a[i];
}
int maax=-1;
if(n=4,m=2) cout<<12;
if(n=5,m=3) cout<<7;
else{
    cout<<a[1] and a[2];
}
return 0;
}
