#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
int s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int mx=0;
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if((a[i]*(i-mid+1))-(s[i]-s[mid-1])<=m){
				ans=mid;
				r=mid-1;
			}else l=mid+1;
		}
		if(ans!=-1)
		mx=max(mx,i-ans+1);
	}
	cout<<mx;
	return 0;
} 
