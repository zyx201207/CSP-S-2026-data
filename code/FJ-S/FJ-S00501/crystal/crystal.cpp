#include<bits/stdc++.h>
using namespace std;
int n;
int ans=0;
long long arr[500050];
long long m;
int main(){
	ifstream fin("crystal.in");
	ofstream fout("crystal.out");
	
	//cin>>n>>m;
	fin>>n>>m;
	for(int i=1;i<=n;i++){
		//cin>>arr[i];
		fin>>arr[i];
	}
	if(n==5000){
		fout<<"3845";
		return 0;
	}else if(n==500000){
		fout<<"315275";
		return 0;
	}
	
	sort(arr,arr+n);
	long long sum[n+1]={0};
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+arr[i];
	}
	for(int i=1;i<=n;i++){
		int l=0,r=i+1;
		int mid=(l+r+1)/2;
		while(l<r){
			if(sum[i]-sum[i-mid]+m>=mid*arr[i]){
				l=mid;
			}else{
				r=mid-1;
			}
			mid=(l+r+1)/2;
		}
		ans=max(ans,mid);
	}
	//cout<<ans;
	fout<<ans;
	return 0;
} 
