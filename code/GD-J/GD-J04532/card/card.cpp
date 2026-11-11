#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[50010];
ll b[50010];
int main(){
	ll n,m,sam;
	int s=0;
	cin>>n>>m;
	 for(int i=0;i<n;i++){
		cin>>a[i];
	 }
	 sam=n;
	 while(sam>0){
	 for(int i=s;i<n;i++){
	 	for(int j=s+1;j<n;j++){
	 		if(a[i]==a[j]){
	 			s=j;
			 }
		 }
	 }
	 for(int e=s;e<n;e++){
	 	int w=a[e];
	 	b[w]+=1; 
		} 
	 sam--;	 	
	 s=n-sam;
	}
	for(int i=0;i<n;i++){
		if(b[i]>0){
		cout<<b[i]<<" ";
	}
	}
}
