#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","d",stdout);
	int n;
	cin>>n;
	string s;
	for(long long i=1;i<=n;i++){
		long long a;
		char b;
		cin>>a>>b;
		for(long long j=1;j<=a;j++){
			s+=b;
		}
	}
	long long sum=0,t=s.size();
	for(int i=0;i<=t/2;i++){
		if(s[i]!=s[t-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
