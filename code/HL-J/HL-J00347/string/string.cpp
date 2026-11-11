#include<bits/stdc++.h>
using namespace std;
string s;
int n,ans,t=1;
long long b;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char a;
		cin>>x>>a;
//		if(i=1) c=a;
//		if(a==c) t++;
//		b+=x;
		for(int j=1;j<=x;j++){
			s=s+a;
		}
	}
//	if(t==n){
//		cout<<0;
//		return 0;
//	} 
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]) ans++;
	}
	cout<<ans;
	return 0;
} 


