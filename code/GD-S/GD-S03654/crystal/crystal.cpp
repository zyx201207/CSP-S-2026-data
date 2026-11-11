#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	
	
	sort(a,a+n);
	long long c[n];
	for(int j=0;j<n;j++){
		long long x=a[j],b[n];
		int ans=0,s=0;
		for (int i=0;i<n;i++){
			if(a[i]>x) b[i]=1e10;
			else b[i]=x-a[i];
		}
		sort(b,b+n);
		for (int i=0;i<n;i++){
			if(ans+b[i]>m) break;
			ans+=b[i];
			s++;
		}
		if(ans==m) c[j]=s;
		else c[j]=-1;
	}
	sort(c,c+n);
	if (c[n-1]==-1){
		for(int j=0;j<n;j++){
		long long x=a[j],b[n];
		int s=0;
		for (int i=0;i<n;i++){
			if(a[i]>x) b[i]=1e10;
			else b[i]=x-a[i];
		}
		sort(b,b+n);
		for (int i=0;i<n;i++){
			if (m-b[i]==0 or m-b[i]==b[i]) s++;
		}
		c[j]=s;
	}
	}
	sort(c,c+n);
	cout<<c[n-1];
	return 0;
}
