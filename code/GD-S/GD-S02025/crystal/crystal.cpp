#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5*1e5+5;
int n,m,a[N],c[N],ans;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//cout<<5*1e5*log2(1e12);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	//cout<<m<<endl;
	sort(a+1,a+n+1);
	//for(int i=1;i<=n;i++)cout<<a[i]<<endl;
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+a[i];
		//cout<<c[i]<<endl;
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;//left p
			int t=i-mid;
			if(t*a[i]-(c[i-1]-c[mid-1])>m)l=mid+1;
			else r=mid;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}
