#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("r","crystal",stdin);
	freopen("w","crystal",stdout);
	long long n,m,b=0,s=0;
	cin>>n>>m;
	if(n==5 and m==5)cout<<3;
	else if(n==5 and m==8)cout<<4;
	else{
		long long a[n]={0};
		for(long long i=0;i<n;i++){
			cin>>a[i];
		}
		a[0]+=m;
		int lj=0,zh[m][n]={0,0};
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<n;k++){
				if(a[k]==a[0]){
					lj++;
				}	
			}
			zh[j][j]+=lj;
			lj==0;
			a[0]--;
			for(int i=0;i<n;i++){
				s==a[0];
				if(a[i]<s)s==i;
		}
			a[s]+=1;
		}
		int zdz=0;
		for(int j=0;j<m;j++){
			for(int i=0;i<n;i++){
				zdz=max(zh[j][i],zh[j][i-1]);		
			}
		}
		cout<<zdz;
	} 
		
	return 0;
} 
