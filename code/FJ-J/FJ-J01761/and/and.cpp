#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	long long a[2005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		int max=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]&a[j]>max){
					max=a[i]&a[j];
				}
			}
		}
		cout<<max;
	}
	else if(m==1){
		int max=0;
		for(int i=1;i<=n;i++){
			if(a[i]>max){
				max=a[i];
			}
		}
		cout<<max;
	}
	else if(m==n-1){
		int max=0,sum;
		for(int i=1;i<=n;i++){
			if(i==1){
				sum=a[2];
			}
			else{
				sum=a[1];
			}
			for(int j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				sum&=a[j];
			}
			if(sum>max){
				max=sum;
			}
		}
		cout<<max;
	}
}
