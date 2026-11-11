#include<bits/stdc++.h>
using namespace std;
long long m,n,a[600005],cha;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.uot","w",stdout);
	cin>>n>>m;
	
	if(n==1){
		cout<<0;
		return 0;
	}
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	sort(a,a+n);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			long long maxa=a[j],sum=0;
			for(int k=i;k<=j;k++){
				sum+=abs(maxa-a[k]);
			}
			if(sum<=m && cha<=j-i+1){
				cha=j-i+1;
			}
		}
	}
	cout<<cha;
	return 0;
} 
