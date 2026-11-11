#include<bits/stdc++.h>
using namespace std;
inline int rea(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-'){
			f=-1;
		}c=getchar();
	}while(c<='9'&&c>='0'){
		x*=10;x+=c-'0';
		c=getchar();
	}return x*f;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n=rea();long long ans=0;string s;
	while(n--){
		int a=rea();char c=getchar();
		while(a--){
			s+=c;
		}
	}int l=(s.size()>>1)-1,r=(s.size()>>1)+(s.size()&1);
	while(~l){
		ans+=s[l--]!=s[r++];
	}cout<<ans;
	return 0;
}
