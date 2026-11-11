#include<iostream>
#include<string>

using namespace std;

int n;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n; 
	string s1="";
	string s2="";
	long long t=0; 
	for(int i=0;i<n;i++){
		long long a;
		char b;
		cin>>a>>b;
		t+=a;
		for(int j=0;j<a;j++){
			s1+=b;
		}
	}
	for(int i=0;i<t;i++) {
		s2+=s1[t-i-1];
	}
	long long ans=0;
	for(int i=0;i<t;i++){
		if(s1[i]!=s2[i]){
			ans++;
		}
	}
	ans/=2;
	cout<<ans<<"\n";
	return 0;
}
