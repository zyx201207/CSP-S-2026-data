#include<bits/stdc++.h>
#define IL inline
#define ll long long
#define ull unsigned long long
#define ri register int
#define F(i,a,b) for(ri i=a;i<=b;i++)
#define FF(i,a,b) for(ri i=b;i>=a;i--)
#define i128 __int128
#define vec vector
using namespace std;
const int N=1e6+5;
const ll inf=0x3f3f3f3f3f3f3f3fLL;
const double eps=1e-9;
string c1,s1,c2,s2,ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		ans+='1';
		if(s1[1]==s2[1]){
			ans+='1';
			if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')){
				cout<<"1100";
				return 0;
			}
			else{
				ans+='1';
				int dif=abs((int)s1[2]-s2[2]);
				if(dif>1){
					cout<<"1110";
					return 0;
				}
				else ans+='1';
				
			}
		}
		else{
			cout<<"1000";
			return 0;
		}
	}
	cout<<ans;
	return 0;
}
/*
关注洛谷 UID 1542698 的用户喵 
完蛋我缺省源没背完 /jk/jk/ll/ll 
目测红（橙/黄）黄（黄/绿） 

qwqwqwqwqwqwqwqwq
qwqwqwqwqwqwqwq
qwqwqwqwqwqwq
qwqwqwqwqwq
qwqwqwqwq
qwqwqwq
qwqwq
qwq
 
8:48 通过所有小样例喵 
哎我怎么 8:40 才开始打的，浪费这么久时间 /ll 
*/
