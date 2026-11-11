#include<bits/stdc++.h>
using namespace std;
long long n,m,ans[1000000],sum;
long long a[1000000],b[1000000];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<(n+1)/2;i++){
	for(int j=0;j<n-1;j++){
		if(a[j]>a[j+1])swap(a[j],a[j+1]);
		for(int i=0;i<n;i++){
	}
	}
}
	for(int i=0;i<n;i++){
		for(int j=0;j<n+1;j++){
			b[j]=a[i]-a[j];
		}
		sum=0;
		for(int j=i;j>0;j--){
			if(sum+a[j]<=m){
				sum+=b[j];
				ans[i]++;
			}
		}
	}
	sum=0;
	for(int i=0;i<n+1;i++){
		if(sum<ans[i])sum=ans[i];
	}
	cout<<sum+1;
	return 0;
}

