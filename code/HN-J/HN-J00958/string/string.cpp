#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long ai;
	char ci;
	for(int i=1;i<=n;i++){
		cin>>ai>>ci;
		for(long long j=1;j<=ai;j++){
			s+=ci;
		}
	}
	long long cnt=0;
	for(long long i=s.size()-1;i>=0;i--){
		a+=s[i];
	}
	for(long long i=0;i<s.size();i++){
		if(s[i]!=a[i]){
			cnt++;
		}
	}
	cout<<cnt/2;
	return 0;
} 
