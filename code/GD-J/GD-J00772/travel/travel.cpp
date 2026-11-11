#include<bits/stdc++.h>
using namespace std;
#define us unsigned
#define ll long long
#define pb emplace_back
#define il inline
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(a);i>=(b);--i)
inline ll read(){
	ll num=0;bool f=1;char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=0;c=getchar();}
	while(c>='0' && c<='9')num=num*10+(c^48),c=getchar();
	return f?num:-num;
}
il ll c(char x){
	if(x=='F' || x=='D')return 1;
	return 2;
}
int main(){
	//ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;cin>>s1>>s2>>s3>>s4;
	if(s1==s3)cout<<'1';
	else return cout<<"0000",0;
	if(s2[0]==s4[0] && s2[1]==s4[1])cout<<'1';
	else return cout<<"000",0;
	if(c(s2[2])==c(s4[2]))cout<<'1';
	else return cout<<"00",0;
	if(abs(s2[2]-s4[2])<=1)cout<<'1';
	else cout<<'0';
	return 0;
}

