#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
int n,ans=0;
cin>>n;
for(int i=0;i<n;i++){
int a,c;
cin>>a>>c;
for(int j=0;j<a;j++)s+=c;
}
int num=s.length()-1;
for(int i=0;i<s.length()/2;i++){
    if(s[i]!=s[num])ans++;
    num--;
}
cout<<ans<<endl;
return 0;
}