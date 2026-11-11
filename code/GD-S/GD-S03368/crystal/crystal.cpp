#include<bits/stdc++.h>
using namespace std;
int n,m,a[5000001],d[10000][10000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){			
		for(int j=1;j<=(n-i);j++){
		     d[i][j]=a[n-i+1]-a[j];	
	    }
	}
	for(int i=1;i<=n;i++){
	   int s=0;
	     for(int j=1;j<=(n-i);j++){			
	        s=s+d[i][j];
     	 }
		  if(s==m){
		  	cout<<n-i+1;
		  	break;
		  }				   
	}
} 
