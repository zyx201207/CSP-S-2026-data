#include <bits/stdc++.h>
using namespace std;

int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);

string s[100005];
int n,b,a[100005];
int m=0;
cin>>n;

for(int i=1;i<=n;i++){
    cin>>a[i]>>s[i];
}

for(int i=1;i<=n;i++){
   b+=a[i];
}

for(int i=0;i<n;i++){
if(s[i]==s[n-i]&&b%2!=0){
    continue;
}
else{
    s[n-i]=s[i];
    m+=1;}

}

cout<<m;


return 0;
}
