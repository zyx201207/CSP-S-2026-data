#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,max2=0;
	cin>>n>>m;
	long long a[n+1]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>max2) max2=a[i];
	}
	if(m==2){
		int ans=0,max=-200;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			int t=a[i]&a[j];
			if(t>max) max=t;
		}
	}
	if(max>ans) ans=max;
	cout<<ans;
	return 0;
	}
	else cout<<max2;
	return 0;
}
