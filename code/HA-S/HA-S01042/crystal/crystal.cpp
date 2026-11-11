#include<bits/stdc++.h>
using namespace std;
long long a[500009];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans=-1;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int as=0;
		long long t=0;
		for(int j=i;j>=1;j--){
			long long h=a[i]-a[j];
			t+=h;
			if(t<=m){
				as++;
			}
			else{
				break;
			}
		}
		if(as>ans){
			ans=as;
		}
	}
	cout<<ans;
	return 0;
}
