#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+10;
const int inf=1e12;
int z[maxn];
int s[maxn];
int n,m;
signed main(){
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int ans=-1;
	for(int i=1;i<=n;i++){
		cin>>z[i];
	}sort(z+1,z+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+z[i];
	}int l=1,r=n;
	int mid;
	while(l<=r){
		mid=(l+r)/2;
		bool can=false;
		for(int i=mid;i<=n;i++){
			int j=i-mid;
			int need=z[i]*mid-(s[i]-s[j]);
			if(need<=m){
				ans=max(ans,mid);
				can=true;
				break;
			}
		}if(can){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}cout<<ans;
	return 0;
}
