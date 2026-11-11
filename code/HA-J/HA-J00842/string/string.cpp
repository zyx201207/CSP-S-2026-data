#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s,v;
long long n,sum;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int e=n/2;
	for(long long i=0;i<n;i++){
		long long q[N];cin>>q[i];
		char w[N];cin>>w[i];
		for(long long j=0;j<q[i];j++){
			s+=w[i];
		} 
	}
	for(long long i=0;i<=s.size();i++){
		if(s[i]!=s[i+1]){
			sum++;
		}else if(s[0]==s[i+1]){
			sum=0;
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	cout<<sum;
	return 0;
}  
