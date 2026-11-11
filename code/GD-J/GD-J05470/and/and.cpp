#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[200005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long b=0;
	if(m==1){
		for(int i=0;i<n;i++){
			if(a[i]>b){
				b=a[i]; 
			} 
		}
	}else if(m==2){
	
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
		    int sum=(a[i]&a[j]);
		    if(sum>b){
		    	b=sum;
			}
		}
	}}
	else if(m==3){
	
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			for(int k=j+1;k<n;k++){
			int sum=(a[i]&a[j]);
		    int ans=(sum&a[k]);
		    if(ans>b){
		    	b=ans;
			}
			}
		}
	}}
	else if(m==n){
	int g=a[0];int ans=0;
	for(int i=1;i<n;i++){
		 ans=g&a[i];
		g=ans;
	}
	if(ans>b){
		b=ans;
	}}
	
	cout<<b;
	return 0;
}
