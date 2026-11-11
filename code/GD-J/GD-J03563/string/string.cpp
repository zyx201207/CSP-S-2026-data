#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s;
	long long num=0;
	long long sum=0;
	for(long long i=1;i<=n;i++){
		long long m;
		char a;
		cin>>m>>a;
		sum+=m;
		for(long long j=1;j<=m;j++){
			s+=a;
		}
	}
	for(long long i=0;i<sum/2;i++){
		if(s[i]!=s[sum-i-1]){
			num++;
		}
	}
	cout<<num;
	return 0;
} 
