#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,maxs=0;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		long long sum=0,cnt=0;
		for(int j=0;j<n;j++){
			if(a[i]<=a[j]){
				sum+=(a[j]-a[i]);
			}else{
				sum+=(a[i]-a[j]);
			}
			if(m-sum>=0){
				cnt++;
			}
		}
		maxs=max(cnt,maxs);
	}
	cout<<maxs;
	return 0;
}
