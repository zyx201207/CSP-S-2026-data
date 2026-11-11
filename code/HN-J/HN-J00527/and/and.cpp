#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200000]={};
	int max1=0;
	int mn=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		max1=max(max1,a[i]);
		if(i==0){
			mn=i;
		}
		else{
			mn&=a[i];
		}
	} 
	if(m==1){
		cout<<max1;
	}
	else if(m==n){
		cout<<mn;
	}
	else if(m==(n-1)){
		int ans1=0;
		int ans2=0;
		for(int i=0;i<m;i++){
			if(i==0){
				ans1=i;
			}
			else{
				ans1&=a[i];
			}
		}
		for(int i=1;i<n;i++){
			if(i==0){
				ans2=i;
			}
			else{
				ans2&=a[i];
			}
		}
		cout<<max(ans1,ans2);
	}
	else if(m==2){
		int max2=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n&&j!=i;j++){
				max2=max(max2,a[i]&a[j]); 
			}
		}
		cout<<max2;
		return 0;
	}
	else{
		int max3=0;
		int ans0=0;
		sort(a+0,a+n+1);
		for(int i=0;i<n;i++){
			if((n-i)<m){
				break;
			}
			else{
				ans0=i;
				for(int j=i+1;j<=m;j++){
					ans0&=a[j];
				}
				max3=max(max3,ans0);
			}
		}
		cout<<max3;
	}
	
	return 0;
	//ccf¸øµã·Ö°É 
}
