#include<bits/stdc++.h>
using namespace std;
int a[1000008];
int b[100000009];
int main(){
//freopen("and.in","r",stdin);
//freopen("and.out","w",stdout);
int n,m,len=0;
cin>>n>>m;
for(int i=0;i<n;i++){
    cin>>a[i];
}
sort(a,a+n,greater<int>());

if(m==1){
    cout<<a[0];
    return 0;
}if(m==2){
    cout<<a[1];
    return 0;
}
return 0;
}


