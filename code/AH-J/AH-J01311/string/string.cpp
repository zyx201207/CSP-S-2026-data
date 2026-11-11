#include <iostream>
#include <cmath>
using namespace std;
long long t,num;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	while(t--){
		long long n;
		string x;
		cin>>n>>x;
		num+=n;
		for(int i=0;i<n;i++) s+=x;
	}
	string a="";
	for(int i=s.size()-1;i>=0;i--) a+=s[i];
	if(a==s){
		cout<<0;
		return 0;
	}
	long long sum=ceil(1.0*s.size()/2);
	for(int i=0,j=s.size();i<s.size()/2,j>=ceil(1.0*s.size()/2);i++,j--){
		if(s[i]==s[j]) sum--;
	}
	cout<<sum;
	return 0;
}
