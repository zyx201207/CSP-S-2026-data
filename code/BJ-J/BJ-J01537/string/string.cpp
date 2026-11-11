#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
cin>>n;
int m;
string a;
string s;
long long c=0;
for(int i=1;i<=n;i++){
    cin>>m>>a;
    for(int j=1;j<=m;j++)s+=a;
}
string h=s;
reverse(s.begin(),s.end());
if(s==h)cout<<0;
else {

    for(int i=0;i<s.size()/2;i++)
    if(s[i]!=s[s.size()-i])c++;
    cout<<c;

}

return 0;
}
