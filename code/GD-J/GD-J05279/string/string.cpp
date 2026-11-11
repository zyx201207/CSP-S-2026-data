#include<bits/stdc++.h>
using namespace std;
long n,sum;
string s,c;
void huei(){
	for(int i=s.size();i>=1;i--){
		c+=s[i-1];
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s+=b;
		} 
	}
	huei();
	if(s==c){
		cout<<0;
		return 0;
	}
	for(int i=0;2*i<=s.size()-1;i++){
		if(s[i]!=c[i]){
			sum++;
			s[i]=c[i];
			c[s.size()-i]=s[i];
			
		} 
	}
	cout<<sum;
	return 0;
}
