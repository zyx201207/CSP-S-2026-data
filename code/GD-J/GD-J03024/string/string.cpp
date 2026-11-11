#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a2,b2;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int a;
		string b;
		cin>>a>>b;
		if(i==1){
			a2=a;
		}
		if(i==2){
			b2=a;
		}
		while(a--){
			s=s+b;
		}
	}
	if(n==1) cout<<0;
	if(n==2) {
		if(a2>=b2) cout<<b2;
		else cout<<a2;
	}
	int mis=0;
	for(int i=1;i<s.size();i++) {
		if(s[i-1]!=s[i]){
			mis++;
			break;
		}
	}
	if(mis==0) cout<<0;
	
	else if(mis==1) cout<<1;
	
	
	return 0;
}
