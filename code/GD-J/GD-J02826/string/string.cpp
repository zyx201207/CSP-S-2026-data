#include <bits/stdc++.h>
using namespace std;
string s,s1,s2;
long long sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		while(a--){
			s+=c;
		}
		
	}
	for(int i=0;i<s.size()/2;i++){
		s1+=s[i];
	}
	for(int i=s.size()-1;i>=s.size()/2;i--){
		s2+=s[i];
	}
	for(int i=0;i<s.size()/2;i++){
		if(s2[i]!=s1[i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
