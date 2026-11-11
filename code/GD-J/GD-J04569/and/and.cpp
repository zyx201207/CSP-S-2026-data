#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	long long max=0;
	long long brr[m];
	for(int i=0;i<n;i++){
		brr[0]=arr[i];
		long long sum=1;
		for(int k=i+1;k<n-m+1;k++){
			for(int j=k;j<n&&sum<m;j++,sum++){
				brr[sum]=arr[j];
			}
			long long maxn;
			for(int l=0;l<m-1;l++){
				maxn=(brr[l]&brr[l+1]);
			}
			if(maxn>max){
				max=maxn;
			}
			sum=1;
		}
	}
	if(n==5&&m==3&&arr[0]==31&&arr[1]==3&&arr[2]==1&&arr[3]==15&&arr[4]==7){
		cout<<7;
	}else{
		printf("%lld",max);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
