#include<bits/stdc++.h>
using namespace std;
long long n,t;
long long a;
char c;
string s,m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	
	if(n==1){
		cout<<0;
		return 0;
	}
	
	for(int i=s.size()-1;i>=0;i--){
		m+=s[i];
	}
	if(s==m){
		cout<<0;
		return 0;
	}
	
	for(int i=0;i<s.size();i++){
		if(s[i]!=m[i]){
			t++;
		}
	}
	cout<<t/2;
	return 0;
}

