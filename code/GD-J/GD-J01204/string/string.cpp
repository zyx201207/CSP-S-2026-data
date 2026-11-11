#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long p=0,cn=0;
	string s="0";
	for(int i=0;i<n;i++){
		int a;
		char c;
		cin>>a>>c;
		p+=a;
		while(a--)
			s+=c;
	}
	for(int i=1;i*2<=p;i++){
		if(s[i]!=s[p-i+1])
			cn++;
	}
	cout<<cn;
	return 0;
} 
