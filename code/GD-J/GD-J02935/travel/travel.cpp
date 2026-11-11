#include <iostream>
#include <cstring>
#include <string.h>
#include <string>
#include <map>
using namespace std;
#define ll long long
inline int read(){
	int f=1,s=0;
	char t=getchar();
	while(t<'0'||t>'9'){
		if(t=='-') f=-1;
		t=getchar();
	}
	while(t>='0'&&t<='9'){
		s=s*10+t-'0';
		t=getchar();
	}
	return f*s;
}
inline void write(int x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
string c1,s1,c2,s2,ans;
map<char,int> mp;
inline int aps(int x){
	if(x>=0) return x;
	else return -x;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	mp['A']=1,mp['B']=1,mp['C']=1;
	mp['D']=2,mp['F']=2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) ans.push_back('1');
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) ans.push_back('1');
	else{
		cout<<"1000";
		return 0;
	} 
	if(mp[s1[2]]==mp[s2[2]]) ans.push_back('1');
	else{
		cout<<"1100";
		return 0;
	}
	if(aps(int(s1[2])-int(s2[2]))==1) ans.push_back('1');
	else{
		cout<<"1110";
		return 0;
	}
	cout<<ans;
	return 0;
}
