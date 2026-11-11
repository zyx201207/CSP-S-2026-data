#include<bits/stdc++.h>
using namespace std;
int b[1000000];
int c[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		
	} 
	long long i=1;
	long long j=1;
	sort(b+1,b+n+1);
	c[j]=b[i];
	long long sum=0;
	while(1){
		i++;
		if(b[i]<c[j]){	
			j++;
			sum++;
			c[j]=b[i];
		 
		} 
		if(sum>=m){
			break;
		}
	}
	
	cout<<b[sum];
} 
