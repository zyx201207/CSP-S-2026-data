#include<bits/stdc++.h> 
using namespace std;
long long a;
string bb,b,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n;
	cin>>n;
	for(long long m=1;m<=n;m++){
		cin>>a;
		cin>>bb;
		for(long long i=1;i<=a;i++){
			b+=bb;
		}
	}
	long long j=0;
	for(long long i=b.size()-1;i>=0;i--){
		c[i]=b[j];
		j++;
	}
	long long sum=0;
	for(long long i=0;i<b.size()/2;i++){
		if(b[i]==c[i]) continue;
		else{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
