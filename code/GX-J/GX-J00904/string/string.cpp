#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
   unsigned long long n,d=0,w=0,sb=0;
   unsigned long long s[26]={0};
   cin>>n;
   while(n--){
    unsigned long long a;
    char c;
    cin>>a>>c;
    s[c-'a']=s[c-'a']+a;
    if(s[c-'a']>=d){
        d=s[c-'a'];
        w=c-'a';
    }
   }
   for(int i=0;i<26;i++){
    if(i!=w){
        sb=sb+s[i];
    }
   }
   cout<<sb;
return 0;
}
