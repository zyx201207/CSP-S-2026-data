#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
ll n;
cin>>n;
ll a[n];
string c[n];
for(ll i=0;i<n;i++){
    cin>>a[i]>>c[i];
}
string s={};
for(ll i=0;i<n;i++){
    for(ll j=0;j<a[i];j++){
        s+=c[i];
    }
}
ll len=s.size();
ll mid;
ll length;
if(len%2==1){
    mid=len/2+1;
    length=mid-1;
}
else{
    mid=len/2;
    length=mid;
}
char l[length]={};
char r[length]={};
if(len%2==1){
    ll k=0;
    for(ll i=0;i<mid-1;i++){
        l[i]=s[i];
    }
    for(ll i=mid;i<len;i++){
        r[k]=s[i];
k++;
    }
}
else{
    for(ll i=0;i<mid;i++){
        l[i]=s[i];
    }
    ll b=0;
    for(ll i=mid;i<len;i++){
        r[b]=s[i];
        b++;
    }
}
ll sum=0;
if(len%2==1){
   for(ll i=0;i<mid-1;i++){
    if(l[i]!=r[length-1-i]){
        sum++;
    }
}
}
else{
   for(ll i=0;i<length;i++){
    if(l[i]!=r[length-i-1]){
        sum++;
    }
}
}
cout<<sum;
//cout<<l<<" "<<r;
return 0;
}
