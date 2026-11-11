#include<bits/stdc++.h>
using namespace std;
int n,m,ans,arr[200050];
int main(){
	cin>>n>>m;for(int i=0;i<n;i++) cin>>arr[i];
	if(m==1){
		int max=0;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			if(x>max) x=max;
		}
		cout<<max;
		return 0;
	}
	if(m==n){
		int x;
		cin>>x;
		int ans=x;
		for(int i=0;i<n-1;i++){
			cin>>x;
			ans&=x;
		} 
		cout<<ans;
		return 0;
	}
	if(m==2){
		
		int max=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(arr[i]&arr[j]>max)max=arr[i]&arr[j];
			}
		}
		return 0;
	}
	if(m==n-1){
		int min=arr[0];
		int minx=0;
		for(int i=0;i<n;i++){
			if(arr[i]<min){
				min=arr[i];
				minx=i;
			}
		}
		int ans=1;
		for(int i=0;i<n;i++){
			if(i==minx)continue;
			ans=ans&i;
		}
		cout<<ans;
	}
}
