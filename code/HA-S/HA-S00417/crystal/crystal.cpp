#include<bits/stdc++.h>
using namespace std;
int n,ans;
const int N=5e5+5;
long long m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1;
	long long now=0;
	while (r<n){
		while (now<=m&&r<n){
			now+=(r-l+1)*(a[r+1]-a[r]);
			r++;
		}
		ans=max(ans,r-l+(now<=m));
		while (now>m&&l<r){
			now-=a[r];
			now+=a[l];
			l++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
