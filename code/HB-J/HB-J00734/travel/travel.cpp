
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sug=123;
int c1,c2;
string s1,s2;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'&&ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1;
	cin>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"1000";
		return 0;
	}
	bool flag=false;
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')) flag=true;
	if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')) flag=true;
	if(!flag){
		cout<<"1100";
		return 0;
	}
	if(abs(s1[2]-s2[2])!=1){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
