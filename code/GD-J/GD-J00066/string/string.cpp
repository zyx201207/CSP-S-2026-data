#include<bits/stdc++.h>
using namespace std;
int main(){freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n,a[200005],cnt=0;
char b[200005];
string s1,s2;
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
for(int i=1;i<=n/2;i++)while(a[i]--)s1+=b[i];
for(int i=n/2+1;i<=n;i++)while(a[i]--)s2+=b[i];
reverse(s2.begin(),s2.end());
for(int i=0;i<s1.size();i++){if(s1[i]!=s2[i])cnt++;
if(s1[i]==s2[i])break;}
cout<<cnt;
return 0;}
