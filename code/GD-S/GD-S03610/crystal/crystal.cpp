#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N]{};
long long sum[N]{};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		bool p=false;
		for(int i=mid;i<=n;i++){
			if(a[i]*mid-(sum[i]-sum[i-mid])<=m){
				p=true;
				break;
			}
		}
		if(p){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
