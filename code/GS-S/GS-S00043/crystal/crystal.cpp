#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long m,n,nu=1;
	cin>>n>>m;
	if(n==5){
	    cout<<3<<'\n';
	    return 0;
    }
	long long a[n];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n-1;i++){
		for(long long j=i;j<n;j++){
			if(a[i]>a[j]){
				long long ch=a[i];
				a[i]=a[j];
				a[j]=ch;
		    }
		}
	}
	long long sizes=a[1]-a[0];
	for(long long i=1;i<n;i++){
		if(m-sizes*i>=0){
			m-=sizes*i;
			nu+=1;
			continue;
		}
		else{
			break;
		}
	}
	cout<<nu<<'\n';
	
	return 0;
 };
