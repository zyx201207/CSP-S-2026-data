#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005];
int ans;
long long h[500005];
long long p=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);   cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	h[n]=1;
	for(int i=n-1;i>=1;i--)h[i]=h[i+1]+a[n]-a[i]+1;
	a[n+1]=a[n]+1;
	for(int i=n;i>=1;i--){
		if(i<=ans)break;
		if(a[i]==a[i+1])continue;
		p+=a[i+1]-a[i];
		int an=0;
		int l=1, r=i-1;
		while(l<=r){
			int mid=(l+r)/2;
			if((h[mid]-h[i])-p*(i-mid)<=m){
				an=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-an+1);
	}
	cout<<ans;
} 
