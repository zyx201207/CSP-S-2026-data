#include <bits/stdc++.h>
using namespace std;
string s="";
int n;
int len=0;
int ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		int x;
		char a;
		cin>>x>>a;
		len+=x;
		for(int i=1;i<=x;++i){
			s+=a;
		}
	}
	s='0'+s;
	for(int i=1;i<= len/2 ;++i){
		if(s[i]!=s[len-i+1]) ans++;
	}
	cout<<ans;
	return 0;
}

