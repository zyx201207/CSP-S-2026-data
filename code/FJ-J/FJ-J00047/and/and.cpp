#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200005]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(m==1){
		cout<<a[n-1];
		return 0;
	}
	else if(m==2){
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j)
				ans=max(a[i]&a[j],ans);
			}
		}
		cout<<ans;
		return 0;
	}
	else if(m==n){
		int ans=0;
		for(int i=0;i<n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	else{
		cout<<1;
	}
	return 0;
	}
