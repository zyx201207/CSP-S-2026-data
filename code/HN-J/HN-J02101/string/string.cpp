#include<bits/stdc++.h>
using namespace std;
long long n;
long long a;
string c,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	string b;
	long long ans;
	ans=s.size()/2;
	for(int i=0;i<ans;i++){
		b+=s[i];
	}
	long long cnt=0;
	for(int i=s.size();i>ans+1;i--){

		if(b[s.size()-i]!=s[i-1])cnt++;
	}
	cout <<cnt;
	return 0;
} 

