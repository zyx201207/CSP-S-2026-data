#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>c1>>s1>>c2>>s2;
if(c1==c2) cout<<1;
else cout<<0;
if(s1/10==s2/10) cout<<1;
else cout<<0;
if(s1/10==s2/10 && 'a'+'b'<=197) cout<<1;
else cout<<0;
if('a'+1=='b') cout<<1;
else cout<<0;

}
