#include<bits/stdc++.h>
using namespace std;
long long n;long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long a[n+10];
	cin>>a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];	
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		a[i]+=a[i-1]; 
	}
	long long min1=m+1,a1[n];
	int e=1;a[n]=0;
	for(int i=1;i<=n;i++){if(((a[i]-a[i-1])*e-(a[i]-a[i-e]))>m){--e;
	}
	++e; 
	}
	cout<<e-1;
	return 0;
} 
