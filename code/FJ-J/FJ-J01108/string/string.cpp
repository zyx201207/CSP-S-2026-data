#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    string s;
	long long n;
	cin>>n;
	int f=0;
	while(n--){
		long long b;
		char m;
		cin>>b>>m;
		f+=b;
		for(long long i=1;i<=b;i++){
			s=s+m;
		}
	}
	long long sum=0;
	for(long long i=0;i<(f+1)/2;i++){
		if(s[i]!=s[f-i-1]){
			sum=sum+1;
		}
	}
	cout<<sum;
	return 0;
} 
