#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int t=0,l=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int sum=0,ans=0;
		sum=a[3]-a[1];
		ans=a[3]-a[2];
		m=m-sum-ans;
		if(m==0){
		a[1]=a[3];
		a[2]=a[3];	
		}
			
	   	if(a[i]==a[3]){
	   	  	l++;
			 } 
	   }
		cout<<l;
	return 0;
} 
