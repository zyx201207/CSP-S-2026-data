#include<iostream>
#include<cstdio>
using namespace std;
long long a[200005],n,len;
char c[200005];
string s,k="1";

int main(){
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(long long j=1;j<=a[i];j++){
			
			s+=c[i];
		
		}
		
	}long long sum=0;
	//cout<<s;
	//cout<<1<<s<<1;
	for(long long i=0;i<s.size()/2;i++){
		//cout<<s[i]<<1<<s[s.size()-i-1];
		if(s[i]-'0'!=s[s.size()-i-1]-'0')sum++;
		}	cout<<sum;
		return 0;}
