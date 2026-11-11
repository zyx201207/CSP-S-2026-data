#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,s;
	string sum,z;
	long long cnt=0;
	cin>>n;
	if(n==1){
		cout<<"0";
		return 0;
		}
	for(long long i=0;i<n;i++){
		cin>>s;
		cin>>z;
		for(long long j=0;j<s;j++){
		sum+=z;
		}
	}
	long long l=0,r=sum.size();
	while(r>=l){
		if(sum[l]==sum[r]){
			l++;
			r--;
		}else{
			sum[r]=sum[l];
			r--;
			l++;
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
