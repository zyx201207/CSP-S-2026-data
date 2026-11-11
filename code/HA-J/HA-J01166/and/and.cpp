#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long a1[200005];
long long b1[200005];
long long c1[200005];
long long aaa(long long a,long long b){
	int i=1,j=1;
	while(a){
		a1[i]=a%2;
		a/=2;
		i++;
	}
//	for(int q=1;q<i;q++){
//		cout<<a1[q]<<" ";
//	}
//	cout<<endl;
	while(b){
		b1[j]=b%2;
		b/=2;
		j++;
	}
//	for(int q=1;q<j;q++){
//		cout<<b1[q]<<" ";
//	}
//	cout<<endl;
	for(int k=1;k<=min(i-1,j-1);k++){
		if(a1[k]==b1[k]){
			c1[k]=a1[k];
			//cout<<a1[k]<<" ";
		}else{
			c1[k]=0;
			//cout<<a1[k]<<" ";
		}
	}
	long long o=min(i-1,j-1)-1;
	long long sum=0;
	for(int k=min(i-1,j-1);k>=1;k--){
		sum+=c1[k]*pow(2,o);
		//cout<<sum<<endl;
		o--;
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long i_=INT_MAX;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		i_=min(i_,a[i]);
	}
	if(m==1){
		long long ma_=-1;
		for(long long i=0;i<n;i++){
			ma_=max(a[i],ma_);
		}	
		cout<<ma_;
		return 0;
	}
	if(m==2){
		long long ma_=-1;
		for(long long i=0;i<n;i++){
			for(long long j=i+1;j<n;j++){
				long long cc_=aaa(a[i],a[j]);
				//cout<<cc_<<" ";
				ma_=max(ma_,cc_);
			}
		}
		cout<<ma_;
		return 0;
	}
	cout<<i_;
	return 0;
}
