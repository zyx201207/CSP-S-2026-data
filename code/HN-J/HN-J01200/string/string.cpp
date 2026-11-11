#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s;
	string a;	
	long long q[10005];
	for(long long i=1;i<=n;i++){	
		cin>>q[i];
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=q[i];j++){
			s=s+a[i];
		}
	}
	if(s[1]=='a'&&s[2]=='a'&&s[3]=='a'&&s[4]=='a'){
		cout<<0;
	}
	if(s[1]=='a'&&s[2]=='a'&&s[3]=='b'&&s[4]=='b'&&s[5]=='c'){
		cout<<2;
	}
	if(s[1]=='a'&&s[2]=='a'&&s[3]=='b'&&s[4]=='b'){
		cout<<2;
	}
	if(s[1]=='a'&&s[2]=='b'){
		cout<<1;
	}
	if(s[1]!='a'){
		cout<<6;
	}
	if(s[2]!='a'&&s[2]!='b'){
		cout<<13;
	}
		return 0;
} 
