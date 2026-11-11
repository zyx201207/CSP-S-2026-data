#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long n,l=0,ans=0;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++){
		int c;
		char a;
		cin>>c>>a;
		for(int j=1;j<=c;j++) s+=a;
		l+=c;
	}
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]) ans++;
	}
	cout<<ans;
	return 0;
} 
