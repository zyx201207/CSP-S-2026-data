#include <bits/stdc++.h>
using namespace std;
long long arr[50005]={0},x[50005]={0},ans[500005]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	bool flag1=0,flag2=0;
	for(long long i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]-arr[i-1]!=1){
			flag1=1;
		}
		if(i!=1){
			if(arr[i]-arr[i-1]!=arr[i-1]-arr[i-2]){
				flag2=1;
			}
		}
	}
	if(flag1==0){
		int i=1;
		for(;i<=n;i++){
			m-=i;
			if(m<0){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}else if(flag2==0){
		int i=1;
		for(;i<=n;i++){
			m-=i*(arr[2]-arr[1]);
			if(m<0){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	sort(arr+1,arr+n+1);
	for(int i=1;i<=n;i++){
		x[i]=arr[i]-arr[i-1];
	}
	ans[1]=1;
	for(long long i=n;i>=1;i--){
		long long y=m,z=0;
		for(long long k=i;k>=1;k--){
			z+=x[k];
			y-=z;
			if(y<0){
				ans[i]=i-k+1;
				break;
			}
		}
		if(y<0){
			continue;
		}
	}
	long long mx=-1;
	for(long long i=1;i<=n;i++){
		mx=max(mx,ans[i]);
	}
	cout<<mx;
	return 0;
}
