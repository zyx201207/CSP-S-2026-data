#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[100001],sum=0,num=1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
sort(a,a+n);
	for(int i=0;i<m;i++){
	
		sum=a[i+1]-a[i]+sum;	
		if(sum<=m){
		a[i]=a[i+1];
		num=num+1;
		}
		else break;
	
		
		
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
