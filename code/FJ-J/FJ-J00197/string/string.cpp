#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		long t;
		char ts;
		cin>>t>>ts;
		s+=string(t,ts);
	}
	long long l=s.size();
	long long sum=0;
	for(long long i=0;i<l/2;i++){
		if(s[i]!=s[l-1-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
