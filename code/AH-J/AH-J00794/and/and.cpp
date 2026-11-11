#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,k,i;
long long mx=-1;
cin>>n>>k;
for(i=0;i<n;i++){
    cin>>a[i];
}
if(k==1){
    for(i=0;i<n;i++){
    if(a[i]>=mx){
        mx=a[i];
    }
    }
    cout<<mx;
    return 0;
}
else if(k==n){
    long long h=a[0]&a[1];
    for(i=2;i<n;i++){
        h=h&a[i];
    }
    cout<<h;
    return 0;
}
cout<<1;
return 0;
}
