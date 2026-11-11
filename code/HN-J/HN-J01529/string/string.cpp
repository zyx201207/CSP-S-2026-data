#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	char a;
	long long n,a1,sum=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a1;
		cin>>a;
		for(long long j=1;j<=a1;j++)
			s+=a;
	}
	string s1="";
	for(long long i=s.size()/2;i>=0;i--)
		s1+=s[i];
	for(long long i=0;i<s1.size();i++){
		if(s1[i]!=s[i])
			sum++;
	}
	cout<<sum;
	
	
	return 0;
}
