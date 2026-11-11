#include<bits/stdc++.h>
using namespace std;
int n,arr[500001],ans,mii;
long long m,temp,c[500001],mic=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool sp=1;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n);
	for(int i=1;i<n;i++){
		c[i]=arr[i+1]-arr[i];
		if(c[i]!=c[i-1]&&i>1){
			sp=0;
		}
	}
	if(sp){
		long long t=0;
		for(int i=1;i<=n;i++){
			t+=i*c[1];
			if(t>m){
				cout<<i;
				return 0;
			}
		}
	}
	for(int i=n;i>1;i--){
		long long cost=0;
		int res=0;
		for(int j=i-1;j>0;j--){
			cost+=arr[i]-arr[j];
			if(cost>m){
				break;
			}
			res+=(res?1:2);
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}