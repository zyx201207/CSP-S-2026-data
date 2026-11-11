#include<bits/stdc++.h>
using namespace std;
int ands(long long a1,long long a2){
	string s1,s2,s3,s4,s5;
	long long a3=a1;
	int ans=0;
	while(a3){
		s1+=a3%2;
		a3/=2;
	}
	for(int i=s1.length()-1;i>=0;i--){
		s2+=s1[i];
	}
 a3=a2;
	while(a3){
		s3+=a3%2;
		a3/=2;
	}
	for(int i=s3.length()-1;i>=0;i--){
		s4+=s3[i];
	}
	for(int i=max(s2.length(),s4.length());i>=0;i--){
		if(s2[i]==1&&s4[i]==1){
			s5+='1';
		}
		else{
			s5+='0';
		}
	}
	int c=1;
	for(int i=s5.length();i>=0;i--){
		ans+=c*s5[i];
		c*=2;
	}
	return ans;
}
int main() {
	long long n,m;
	cin>>n>>m;
	long long a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		long long sum=ands(a[1],a[2]);
		for(int i=3;i<=n;i++){
			sum=ands(sum,a[i]);
		}
		cout<<sum;
		return 0;
	}
	if(m==2){
		long long sum=-1;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				long long b=ands(a[i],a[j]);
				sum=max(sum,b);
			} 
		}
		cout<<sum;
		return 0;
	}
	return 0;
}
