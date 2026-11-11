#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum1=0;
	string s="";
	cin>>n;
	for(long long i=0;i<n;i++){
		int m;
		char s1;
		cin>>m>>s1;
		sum1+=m;
		for(long long j=0;j<m;j++){
			s+=s1;
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}else if(n==2){
		if(sum1%2==0){
			cout<<0;
			return 0;
		}
	}
	string s2="";
	for(int i=s.length()-1;i>=0;i--){
		s2+=s[i];
	}
	if(s==s2){
		cout<<0;
		return 0;
	}
	long long i=0,j=sum1-1,sum=0;
	while(i!=j){
		if(s[i]!=s[j]){
			sum++;
			i++;
			j--;
		}
	}
	cout<<sum;
	return 0;
}
