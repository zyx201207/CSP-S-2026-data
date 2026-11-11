#include<bits/stdc++.h>
using namespace std;
string s,p,s2;
long long n,num,l;
bool abc(string x){
    long long sum=0;
for(long long i=0;i<l;i++){
    if(x[i]==x[l-1-i]){
        sum++;
    }
}
if(sum==l){
    return true;
}
return false;
}
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
long long m1=n;
while(m1--){
    cin>>num>>p;
    l+=num;
    while(num--){
        s+=p;
    }
}
if(n==1){
    cout<<0;
    return 0;
}
if(abc(s)){
    cout<<0;
   return 0;
}
    long long k=0;
    for(long long i=0;i<l;i++){
        s2[l-1-i]=s[i];
    }
    for(long long i=0;i<l;i++){
        if(s[i]!=s2[i]){
            k++;
        }
    }
    cout<<k/2;
return 0;
}