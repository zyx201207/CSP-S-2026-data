#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string1.in","r",stdin);
freopen("string1.out","w",stdout);
long long n;
cin>>n;
long long sh[n],s=0;
char zi[n];
for(long long i=0;i<n;i++){
cin>>sh[i]>>zi[i];
s+=sh[i];
}
long long a[s];
s=0;
for(long long i=0;i<n;i++){
for(long long j=1;j<=sh[i];j++){
a[s]=zi[i];
s++;
}
}
long long z=s-1,s2=0;
for(long long i=0;i<s/2;i++){
if(a[i]!=a[z])s2++;
z--;
}
cout<<s2;
return 0;
}
