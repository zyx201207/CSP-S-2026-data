#include<bits/stdc++.h>
using namespace std;
#define maxn 1000100
#define int long long
int n,m;
int s[maxn],a[maxn],ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-s[i]+s[mid-1]<=m){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
