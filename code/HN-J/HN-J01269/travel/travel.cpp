#include<bits/stdc++.h>
#define int long long
using namespace std;
string a1,a2,b1,b2;
int suan(string s){
	int cnt=0;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9') cnt=cnt*10+s[i]-'0';
		else return cnt; 
	}
	return cnt;
}
bool pan1(){
	if(suan(a1)==suan(b1)) return 1;
	else return 0;
}
bool pan2(){
	if(suan(a2)==suan(b2)) return 1;
	else return 0;
}
bool pan3(){
	if((a2[2]=='A'||a2[2]=='B'||a2[2]=='C')&&(b2[2]=='D'||b2[2]=='F')) return 0;
	if((b2[2]=='A'||b2[2]=='B'||b2[2]=='C')&&(a2[2]=='D'||a2[2]=='F')) return 0;
	return 1;
} 
bool pan4(){
	if(a2[2]=='A'&&b2[2]=='B') return 1;
	if(a2[2]=='B'&&b2[2]=='C') return 1;
	if(a2[2]=='C'&&b2[2]=='D') return 1;
	if(a2[2]=='D'&&b2[2]=='F') return 1;
	if(b2[2]=='A'&&a2[2]=='B') return 1;
	if(b2[2]=='B'&&a2[2]=='C') return 1;
	if(b2[2]=='C'&&a2[2]=='D') return 1;
	if(b2[2]=='D'&&a2[2]=='F') return 1;
	return 0;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(pan1()) cout<<1;
	else cout<<0;
	if(pan1()&&pan2()) cout<<1;
	else cout<<0;
	if(pan1()&&pan2()&&pan3()) cout<<1;
	else cout<<0;
	if(pan1()&&pan2()&&pan3()&&pan4()) cout<<1;
	else cout<<0;
	return 0;
} 
