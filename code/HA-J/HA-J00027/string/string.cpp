#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 200005

ll a[MAXN],n,ans,vis[MAXN],len;

char c[MAXN];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	ll l=0,r=n-1;
	while(l<r){
		if(vis[l]==1) l++;
		if(vis[r]==1) r--;
		if(c[l]!=c[r]){
			if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				vis[l]=1;
				l++;
			}
			else if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				vis[r]=1;
				r--;
			}else{
				ans+=a[l];
				a[l]=a[r]=0;
				vis[l]=vis[r]=1;
				l++;
				r--;
			}
		}else{
			if(a[l]<a[r]){
				a[r]-=a[l];
				vis[l]=1;
				l++;
			}
			else if(a[l]>a[r]){
				a[l]-=a[r];
				vis[r]=1;
				r--;
			}else{
				a[l]=a[r]=0;
				vis[l]=vis[r]=1;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
