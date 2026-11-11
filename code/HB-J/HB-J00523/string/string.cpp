#include<iostream>
using namespace std;
string ll[1000000]={};
int main(){
// freopen("string.in","r",stdin);
 // freopen("string.out","w",stdout);
int n,t,ans=0,len=1;
string s;
cin>>n;
for(int i=1;i<=n;i++){
    cin>>t>>s;

    for(int i=len;i<=t+len;i++){
        ll[i]=s;
        len+=t;
    }
}
for(int i=1;i<=len/2;i++){
    if(!(ll[i]==ll[len]))ans++;
}
cout<<ans;
//fclose(stdin);
//fclose(stdout);
return 0;}
