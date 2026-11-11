#include<bits/stdc++.h>
using namespace std;
long long ans;
int n,a;
string s;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i])
			ans++;
	}
	cout<<ans;
	return 0;
}
/*
6
10000 a
10000 a
10000 a
10000 b
10000 b
100000 b
*/
