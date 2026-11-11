#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long diff[500005];
long long fr[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		a[i]=0;
		diff[i]=0;
		fr[i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		diff[i]=a[i+1]-a[i];
		fr[i]=diff[i]+fr[i-1];
	}
	fr[n]=fr[n-1];
	int mx=0;
	int l=1,r=n;
	for(int l=1;l<n;l++){
		for(int r=n;r<=n;r++){
			if((fr[r]-fr[l-1])<=m)mx=max(mx,r-l+1);
		} 
	}
	
	/*for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		cout<<diff[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		cout<<fr[i]<<" ";
	}
	cout<<endl;*/
	
	cout<<r-l+1;
	return 0;
}
