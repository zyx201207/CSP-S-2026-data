#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,cnt=0;
struct s{
ll a;
char c;	
}st[300005];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(NULL);
cin>>n;
for(ll i=1;i<=n;i++)cin>>st[i].a>>st[i].c;
ll l=1,r=n;
while(l<=r){
if(st[l].c==st[r].c){
if(st[l].a>st[r].a){st[l].a-=st[r].a;r--;}
else if(st[l].a==st[r].a){l++;r--;}
else {st[r].a-=st[l].a;l++;}	
}	
else {
if(st[l].a>st[r].a){cnt+=st[r].a;st[l].a-=st[r].a;r--;}
else if(st[l].a==st[r].a){cnt+=st[l].a;l++;r--;}
else{cnt+=st[l].a;st[r].a-=st[l].a;l++;}	
}
}
cout<<cnt;
return 0;
}
