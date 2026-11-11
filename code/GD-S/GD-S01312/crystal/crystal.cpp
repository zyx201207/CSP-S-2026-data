#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005],ans;
int s[500005];
int lower(int x){
	int l=1,r=x,res;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[x]*(x-mid)-(s[x-1]-s[mid-1])<=m){
			r=mid-1;
			res=mid;
		}else l=mid+1;
	}return res;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int u=lower(i);
		ans=max(ans,i-u+1);
	}cout<<ans;
	return 0;
} 
