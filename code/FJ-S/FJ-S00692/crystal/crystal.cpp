#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
long long a[500005],s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		int l=1,r=i,an=i+1;
		while(l<=r){
			int mid=(l+r)>>1;
			long long rt=a[i]*(i-mid+1)-(s[i]-s[mid-1]);
			if(rt<=m){
				r=mid-1;
				an=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-an+1);
	}
	cout<<ans;
	return 0;
}
