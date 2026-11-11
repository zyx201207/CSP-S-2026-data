#include<bits/stdc++.h>
using namespace std;
const int nm=5e5+5;
int n,m,ans;
long long a[nm],cnt[nm];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=0;
	for(int i=1;i<=n;i++){
		int r=i-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[i]*mid-cnt[i-1]+cnt[i-1-mid]<=m)l=mid+1;//区间能变成当前的 
			else r=mid-1;
		}
		ans=max(ans,l);
		cnt[i]=cnt[i-1]+a[i];
	}
	cout<<ans;
	return 0;
}
