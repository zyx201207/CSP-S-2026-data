#include<bits/stdc++.h>
using namespace std;
const int mx=300030,mmx=500030;
string s,pz;
int n,m,i,j,a[mx],z,f;
char c,zu;
int wan(){
string pz;
for(i=0;i<=n;i++){
        f=pz.find(s[i]);
    if(f<=pz.size()-1&&f>=0){
        pz=pz.substr(0,f+1);
    }
else pz=pz+s[i];
}
for(i=0;i<pz.size();i++){
  a[pz[i]-'0']++;
}
}
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
for(i=0;i<n;i++){
    cin>>c;
    s=s+c;
}
while(n--){
    wan();
    s=s.substr(1,n+1);
}
for(i=0;i<m+1;i++){
    if(a[i])cout<<a[i]<<" ";
}
return 0;
}
