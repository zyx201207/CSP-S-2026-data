#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
long long a[maxn];
char c[maxn];
string s;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
cin>>n;
for(int i=1;i<=n;i++){
cin>>a[i]>>c[i];
while(a[i]--)s+=c[i];
}
long long l=s.size(),lh=s.size()/2,ans=0;
s=' '+s;
for(long long i=1;i<=lh;i++){
if(s[i]!=s[l+1-i])ans++;
}
cout<<ans;
return 0;
}
