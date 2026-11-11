#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
int val[50],pass;
}s[N];
int n,m,len=30;
long long ans;
void invit(long long a,int id){
int cnt=30;
while(a){
    s[id].val[cnt--]=a%2;
    a=a/2;
    }
    len=min(len,cnt);
}
bool pan(int k){
 int res=0;
 for(int i=1;i<=n;i++)if(s[i].val[k]&&!s[i].pass)res++;
 return res>=m;
}
long long pow(int k){
    long long res=1;
    while(k--)res=res*2;
    return res;
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
long long a;
cin>>a;
invit(a,i);
}
for(int i=len;i<=30;i++){
   if(pan(i)){
   ans+=pow(30-i);
   for(int j=1;j<=n;j++)if(!s[j].val[i])s[j].pass=1;
   }
}
cout<<ans;
return 0;
}
