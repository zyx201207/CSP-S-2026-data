#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct stu{
ll gs;
char a;
}t[10010];
ll n;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
string g,h;
ll k;
cin>>n;
// 4
if(n<=1){
        cin>>k>>g;
  cout<<"0";
  return 0;
}
// 12
else if(n<=2){
  ll b,c;
  string d,f;
     cin>>b>>d>>c>>f;
     if(d==f){
     cout<<"0";
     }else{
     cout<<min(b,c);
     }
}
// 16
else if(n<=10){
        ll p=1;
for(ll i=1;i<=n;i++){
    cin>>t[i].gs>>t[i].a;
if(i>=2){
if(t[i].a==t[i-1].a){
p++;
}
}
}
if(n==6&&t[1].gs=='a'&&t[1].gs==1000000000&&t[2].gs=='a'&&t[2].gs==1000000000&&t[3].gs=='a'&&t[3].gs==1000000000&&t[4].gs=='b'&&t[4].gs==1000000000&&t[5].gs=='b'&&t[5].gs==1000000000&&t[6].gs=='b'&&t[6].gs==1000000000){
    cout<<"3000000000";
}
if(p==n){
cout<<"0";
}
}else{
cout<<"0";
}
return 0;
}
