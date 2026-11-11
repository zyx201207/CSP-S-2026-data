#include<bits/stdc++.h>
using namespace std;
int n,m,e,s;
int num[500005];
int t=1,p=1,sum=1,d=1;
int mn=INT_MAX;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	
		cin>>num[i];
		
	}
	
	for(int i=1;i<=n;i++){
		int d=(num[n]-num[1])/(n-1);
		if(num[i]!=i)t++;
	    d=num[2]-num[1];
	    if(num[i]!=num[1]+(i-1)*d && i>1)p++;
	    if(num[i]>0)d++;
		}
		if(t==1){
			for(int i=1;i<=n;i++){
				e=e+i;
				sum++;
				if(m>(n*n)/2){
				cout<<n;
				 return 0;}
			    else if (e>m){
			    	cout<<sum-1;
			    	return 0;
				}
				
			}
		}
		if(p==1){
			int d=(num[n]-num[1])/(n-1);
				for(int i=1;i<=n;i++){
				e=e+i*d;
				sum++;
				if(m>(n*n)/2){
				cout<<n;
				 return 0;}
			    else if (e>m){
			    	cout<<sum-1;
			    	return 0;
				}
				
			}
		}
	if(p!=1 || t!=1){
		for(int i=1;i<=n;i++){
			s=s+i*(num[i+1]-num[i]);
			sum++;
			if(s>m){
				cout<<sum-1;
				return 0;
			}
			if(s==m){
				cout<<sum;
				return 0;
			}
		}
	}
	if(d==1){
		for(int i=1;i<=n;i++){
			if(num[i]<mn)mn=num[i];
			}
			int r=0-mn+1;
			for(int i=1;i<=n;i++){
				num[i]=num[i]+r;
			}
				for(int i=1;i<=n;i++){
			s=s+i*(num[i+1]-num[i]);
			sum++;
			if(s>m){
				cout<<sum-1;
				return 0;
			}
			if(s==m){
				cout<<sum;
				return 0;
			}
		}
	}	
	
	return 0;
}
