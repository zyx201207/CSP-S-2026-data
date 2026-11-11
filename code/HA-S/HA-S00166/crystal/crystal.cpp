#include<bits/stdc++.h>
using namespace std;
int n,m,s=0,i=1;
int a[50005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int k=0;k<n;k++){
		cin>>a[k];
	}
	for(i=1;i<=n;i++){
		
		if(s<=m){
			s=0;
			for(int j=0;j<i;j++){
				s=a[i]-a[j]+s;
			}
			
		}
		else{
			
			break; 
		}
		
	}
	cout<<i-1;
	
	return 0;
} 
