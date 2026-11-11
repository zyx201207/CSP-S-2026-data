#include <bits/stdc++.h>
using namespace std;
string s;long long n,m,u;char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","l",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>c[i];
		for(int j=1;j<=m;j++){
			s+=c[i];
		}
	}
	string z="";
	for(int i=s.size()-1;i>=0;i--){
		z+=s[i];
	}
	if(s==z){
		cout<<0;
		return 0;
	}
	z="";
	long long k=s.size();
	long long o=ceil(k*1.0/2);
	for(int i=0;i<o;i++){
		z=s[i]+z;
	}
	for(int i=o;i<s.size();i++){
		if(s[i]!=z[i-o+1])u++;
	}
	cout<<u;
	return 0;
}
