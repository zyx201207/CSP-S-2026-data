#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,x[10000000001]={},cnt=0,index=0;
	cin>>n;
	long long s[10000000001]={},s1[10000000001]={},s2[10000000001]={};
	for(int i=0;i<n;i++){
		cin>>x[i]>>s[i];
		cnt+=x[i];
	}
	cnt/=2;
	for(long long i=0;i<n;i++){
		for(long long j=0;j<x[i];j++){
			s1[index]=s[i];
		}
	}
	index=0;
	for(long long i=n;i>0;i--){
		for(long long j=0;j<x[i];j++){
			s1[index]=s[i];
		}
	}
	long long o=cnt;
	for(int i=0;i<o;i++){
		if(s1[i]==s2[i]){
			cnt--;
		}
	}
	cout<<cnt;
	return 0;
}
