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
int n;
ll len,ans;
string t;
struct String{
	ll a;
	char c;
} s[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	F(i,1,n){
		cin>>s[i].a>>s[i].c;
		F(j,1,s[i].a) t+=s[i].c;
		len+=s[i].a;
	}
//	cout<<"t:"<<t<<" len:"<<len<<'\n';
	ll l=(len%2==0?len/2:(len/2+1))-1,r=len/2;
	if(t[l]!=t[r]) ans++;
//	cout<<"t_l:"<<t[l]<<" t_r:"<<t[r]<<" ans:"<<ans<<'\n';
	while(0<=l&&r<len-1){
		l--,r++;
		if(t[l]!=t[r]) ans++;
//		cout<<"t_l:"<<t[l]<<" t_r:"<<t[r]<<" ans:"<<ans<<'\n';
	}
	cout<<ans;
	return 0;
}
/*
in:
6
2 a
3 a
4 b
3 a
5 c
6 c
out:
11
*/

/*
怎么有 string，请输入文本 
哦好像不是很难
先打个 O(\sum a_i) 的暴力
似乎只有 68pts，考虑优化
有思路了
怎么打
咋没时间了，，， 
*/
