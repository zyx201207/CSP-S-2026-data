#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","w",stdin);
freopen("string.out","r",stdout);
long long n,n0,last_n=0,cnt=0,len; char s0;
char s[8300000];
cin >> n;
for (int i=0;i<n;i++){
    cin >> n0 >> s0;
    last_n=n0;
    len=len+n0;
    for (int j=0;j<n0;j++){
        s[i*last_n+j]=s0;
    }
}
for (int i=0;i<=len/2;i++){
    if (s[i]!=s[len-i-1]){
        cnt++;
    }
}
cout<<cnt;
return 0;}
