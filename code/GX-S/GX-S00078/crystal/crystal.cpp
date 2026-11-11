#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	long long nlz;
	long long ans=0;
	long long mm=m;
	for(int i=0;i<n;i++){
		m=mm;
		if(a[i]!=a[i-1]) nlz=a[i];
		else continue;
		long long Nans=0;
		for(int j=i;j>=0;j--){
			if(nlz-a[j-1]<=m){
				m-=nlz-a[j-1];
				Nans++;
			}
		}
		for(int j=i;j<n;j++){
			if(a[j]==nlz) Nans++;
			if(a[j]>nlz) break;
		}
		if(Nans>ans) ans=Nans;
	}
	
	cout<<ans-1;
	return 0;
}
