#include<bits/stdc++.h>
using namespace std;
long long n[500009];
long long geshu=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
long long a,b;
cin>>a>>b;
if(a==1){
    cout<<geshu;
    return 0;
}else{
for(long long i=0;i<a;i++){
    cin>>n[i];
}
for(long long i=0;i<a;i++){
        b=b-(n[1]-n[0])*(i+1);
if(b<0){
    break;
}
        geshu++;
}
cout<<geshu;
}
return 0;
}
