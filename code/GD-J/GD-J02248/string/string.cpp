#include<bits/stdc++.h>
using namespace std;

int n;
int ans;
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	
	
	long long t=1;
	
	for(int i=1;i<=n;i++){
		int a; cin>>a;
		char c; cin>>c;
		while(i--){
			s[t++]=c;
		}
	}
	
	for(int i=1;i<=t/2;i++){
		if(s[i]!=s[t+1-i]) ans++;
	}
	cout<<ans;
	return 0;
} 
