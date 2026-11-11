#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
string a,b,c,d;
string n,m;
signed main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>a>>b>>c>>d;
if(a==c)cout<<1;
else {cout<<0<<0<<0<<0;return 0;
}
 n+=b[0];n+=b[1];
 m+=d[0];m+=d[1];
if(n==m)cout<<1;
else {cout<<0<<0<<0;
return 0;
}
char s1=b[2],s2=d[2];
if(s1<='C'&&s2<='C')cout<<1;
else if(s1>'C'&&s2>'C')cout<<1;
else {cout<<0<<0;return 0;
}
if(s1=='A'&&s2=='B')cout<<1;
else if(s1=='B'){
if(s2=='C'||s2=='A')cout<<1;
}
else if(s1=='D'&&s2=='F')cout<<1;
else if(s1=='C'&&s2=='B')cout<<1;
else cout<<0;

return 0;
} 
