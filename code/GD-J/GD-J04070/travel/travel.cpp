#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
using namespace std;
//#define getc() (uu==vv&&(vv=(uu=In)+fread(In,1,1<<15,stdin),uu==vv)?EOF:*uu++)
//template<class T>
//void R(T &x){
//	char c=getc();x=0;bool f=0;
//	for(;!isdigit(c);f|=(c=='-'),c=getc());
//	for(;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=getc());
//	f&&(x=-x);
//}
using ll = long long;
void solve(){
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	int c1=s2[2],c2=s4[2];
	bool p1=s1==s3,p2=(s2[0]==s4[0])&(s2[1]==s4[1]),p3=(c1<='C')==(c2<='C'),p4=false;
	if(c1>c2)swap(c1,c2);
	if(c1!='C'&&c1+1==c2)p4=true;
	cout<<p1<<(p1&p2)<<(p1&p2&p3)<<(p1&p2&p3&p4)<<'\n';
}
int main(){
//	ios::sync_with_stdio(false),cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	solve();
	return 0;
} 
// 00 00D 00 00C
