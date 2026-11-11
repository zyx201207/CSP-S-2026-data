#include <bits/stdc++.h>
using namespace std;
long long arr[2000005]={0};
char arr2[2000005];
int main(){
freopen ("string.in","r,"stdin);
freopen("string.out","w",stdout);
string a,b;
int n;
cin>>n;
for(int i=0;i<n,i++){
    cin>>arr[i]>>arr[2];
}
for(int i=0;i<n,i++){
        for(j=arr[i];i>0;i--){
        b+=arr2[i];
    }
}
for(int i=n;i>0;i--){
    for(j=arr[i];i>0;i--){
        a+=arr2[i];
    }
}
if(b==a){
    cout<<0;
}
else{
    cout<<1;
}
return 0;
}
