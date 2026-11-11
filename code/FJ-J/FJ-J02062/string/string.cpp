#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	int k;cin>>k;
	for(int i=1;i<=k;i++){
		int n;cin>>n;
		char c;cin>>c;
		for(int j=1;j<=n;j++)
		s+=c;
	}
	long long l=s.size(),cnt=0;
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]){
		cnt++;
	}
	}
	cout<<cnt;
	return 0;
} 

