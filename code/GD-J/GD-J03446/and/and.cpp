#include<bits/stdc++.h> 
using namespace std;
int n,m,a[20005];
int sum=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum & a[i];
		}
	}
	else if(m==1){
		sum=a[1];
		for(int i=2;i<=n;i++){
			sum=max(sum,a[i]);
		}
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				sum=max(sum,a[i]&a[j]);
			}
		}
	}
	cout<<sum; 
}
