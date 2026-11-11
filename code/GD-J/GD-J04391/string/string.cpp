#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n,a,sum=0;
	cin>>n;
	char c;
	string s="",s1="";
	for(long long i=0;i<n;i++){
		scanf("%lld %c",&a,&c);
		for(long long j=0;j<a;j++){
			s=s+c;
			s1=c+s1; 
		}
	}
	long long l=s.size();
	if(s1==s){
		cout<<0;
		return 0;
	}
	for(long long i=0;i<l;i++){
		if(s[i]!=s1[i]){
			s1[i]=s[i];
			sum++;
		}
		string s2=s1;
		reverse(s2.begin(),s2.end());
		if(s1==s2) break;
	}
	cout<<sum;
	
	
	
	
	return 0;
} 
