#include<bits/stdc++.h> 
using namespace std;
int main(){
	long long n,m;
	cin>>n>>m;
	int a[n+5],dp[n+5],ans[m+5]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long i=0,l=0;
	bool t=true;
	while(i<n){
		for(int j=i;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(a[j]==a[k]){
					t=false;
					j=k-1;
					break;
				}
			}
			if(t){
				dp[l]=a[j];
				l++;
			}
			t=true;
		}
		for(int j=0;j<l;j++){
			ans[dp[j]]++;
		}
		i++;
		l=0;
	}
	for(int j=1;j<=m;j++){
		cout<<ans[j]<<' ';
	}
	return 0;
}
