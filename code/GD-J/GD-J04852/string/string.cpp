#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,ans=0;
	char c,s[1000005];
	cin>>n;
	if(n==1){
		cin>>a>>c;
	cout<<0;
	return 0;	
	}
	if(n==2){
			cin>>a>>c;
			s[1]=c;
			cin>>a>>c;
			s[2]=c;
		if(s[1]-'0'==s[2]-'0'){
		cout<<0;
		return 0;
		}
		else{
			cout<<1;
			return 0;
		}
	}
	return 0;
} 
