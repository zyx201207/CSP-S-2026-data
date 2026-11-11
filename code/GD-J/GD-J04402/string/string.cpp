#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		for(int j=1;j<=x;j++){
			s+=y;
		}
	}
	int len=s.size(),cnt=0;
	for(int i=1;i<=(len+1)/2;i++){
		if(s[i]!=s[len-i]) cnt++;
	}
	cout<<cnt;
	return 0;
}
