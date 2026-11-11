#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum;
	long long a;
	string s="";
	char c;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long i=1;i<=a;i++){
			s+=c;
		}
	}
	bool f=1;
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			sum+=1; 
		}
	}
	cout<<sum;
	return 0;
} 
