#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]&&i!=1){
			f=false;
		}
	}
	if(f==true){
		cout<<n;
		return 0;
	}
	sort(a+1,a+1+n);
	long long ans1=1;
	for(int i=1;i<=n;i++){
		int j=1;
		ans1=1;
		while(i+j<=n||i-j>=1){
			if(i+j<=n){
				if(max(a[i],a[i+j])-min(a[i],a[i+j])<=m){
					m-=max(a[i],a[i+j])-min(a[i],a[i+j]);
					ans1++;
				}
			}
			if(i-j>=1){
				if(max(a[i],a[i-j])-min(a[i],a[i-j])<=m){
					m-=max(a[i],a[i-j])-min(a[i],a[i-j]);
					ans1++;
				}
			}
			j++;
		}
		ans=max(ans,ans1);
	}
	cout<<ans;
	return 0;
}
