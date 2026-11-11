#include<bits/stdc++.h>
using namespace std;
long long n,sum=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int j=0;j<a;j++){
			s+=b;
		}
	}
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
