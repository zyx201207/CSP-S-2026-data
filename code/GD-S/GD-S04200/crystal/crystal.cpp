#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m;
	long long n;
	cin>>n>>m;
	long long arr[600000]={};
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	/*if(n>5000){
		int cha=arr[1]-arr[0];
		int ans=0;
		int k=1;
		while(ans<n&&m>=k*cha){
			m-=k*cha;
			k++;
			ans++; 
		}
		cout<<ans;
		return 0;
	}*/
	sort(arr,arr+n);
	long long mans=1,k=1;
	long long l=0;
	for(int i=1;i<n;i++){
		while(m<k*(arr[i]-arr[i-1])){
			m+=arr[i-1]-arr[l];
			l++;
			k--;
		}
		m-=k*(arr[i]-arr[i-1]);
		k++;
		mans=max(mans,k);
	}
	cout<<mans;
	return 0;
}
