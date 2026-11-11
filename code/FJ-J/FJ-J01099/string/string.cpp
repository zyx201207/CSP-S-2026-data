#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;
		char c;
		cin>>m>>c;
		for(int j=1;j<=m;j++) s+=c;
	}
	int len=s.size();
	for(int i=0;i<len/2;i++){
		if(s[len-1-i]!=s[i]) ans++;
	}
	cout<<ans;
	return 0;
}
