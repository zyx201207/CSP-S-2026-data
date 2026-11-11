#include<bits/stdc++.h>
using namespace std;
string m,w;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n,cnt=0,sum=0;
	cin>>n;
	for(long long i=0;i<n;i++){
		long long a=0;
		cin>>a;
		string b;
		cin>>b;
		for(long long j=0;j<a;j++){
			m+=b;
		}
		cnt+=a;
	}
	long long x=cnt;
	while(cnt--){
		w+=m[cnt];
	}
	for(long long i=0;i<x;i++){
		if(w[i]!=m[i]){
			sum++;
		}
	}
	if(sum==0){
		cout<<0;
	}
	else{
		cout<<sum;
		
	}
	return 0;
}
