#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010];
long long qz[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],qz[i]=qz[i-1]+a[i];
	int mx=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1;
		int ans;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-qz[i]+qz[mid-1]<=m) ans=mid,r=mid-1;
			else l=mid+1;
		}
		mx=max(mx,i-ans+1);
	}
	cout<<mx;
	return 0;
} 
