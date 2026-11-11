#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long arr[200005],arr2[200005];
long long ans=0;
long long arr1[200005][200005]; 
void spa(long long number,long long k,long long h){
	while(number>0){
		arr1[k][h++]=number%2;
		number/=2;
	}
	k++;
}
long long spb(long long l){
	int sum1=1,l1=l+1;
	while(l1--){
		sum1*=2;
	}
	return sum1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(long long i=0;i<n-m;i++){
		long long k=0;
		long long h=0;
	 	for(long long j=0;j<m;j++){
	 		long long number=arr[i+j];
	 		spa(number,k,h);
	 	}
	 	for(long long j=0;j<h;j++){
	 		long long sum;
	 		for(int l=0;l<k;l++){
	 			sum+=arr1[j][l];	
			 }
			if(sum==0||sum==m){
			 	arr2[j]=1;
			}
		 }
		 long long ans1=0;
		 for(long long l=0;l<h;l++){
		 	ans+=arr[l]*spb(l);
		 }
		 ans=max(ans,ans1);
	}
	cout<<ans;
	return 0;
}
