#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,m1;
	int ans=0,ans1=-1e9;
	int a[50001];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	m1=m;
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		int j=i-1;
		m=m1;
		while((a[i]-a[j])<=m && j>=0){
			
			if(a[i]-a[j]<=m){
				ans+=1;
			}
			m-=(a[i]-a[j]);
			j--;
		}
		ans+=1;
		if(ans>=ans1){
			ans1=ans;
		}
		ans=0;
	}
	cout<<ans1;
	return 0;
}
