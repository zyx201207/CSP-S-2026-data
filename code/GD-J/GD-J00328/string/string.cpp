#include<bits/stdc++.h>
using namespace std;
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string s,s1;
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s+=c;
		}
	}
	for(long long i=0;i<s.size()/2;i++){
		s1+=s[i];
	}
//	cout<<s1<<"\n";
	for(long long i=s1.size()-1;i>=0;i--){
//		cout<<s1[i]<<" "<<s[i+s.size()/2];
		if(s1[i]!=s[i+s.size()/2]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
