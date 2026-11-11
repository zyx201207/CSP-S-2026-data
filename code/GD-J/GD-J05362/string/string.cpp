#include<bits/stdc++.h>
using namespace std;
int n,a;
long long ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++) s+=c;
	}
	int l=s.size()/2;
	for(int i=0;i<l;i++){
		if(s[i]!=s[l-i-1]) ans++;
	}
	cout<<ans;
	return 0;
} 
