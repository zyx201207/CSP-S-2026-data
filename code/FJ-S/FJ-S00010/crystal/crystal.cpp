#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int s[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		//cout<<"s "<<s[i]<<endl;
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(((i-mid+1)*a[i])-(s[i]-s[mid-1])<=m){
				ans=i-mid+1,r=mid-1;
				//cout<<(s[i]-s[mid-1])<<" "<<(i-mid+1)*a[i]-(s[i]-s[mid-1])<<endl;
			}
			else l=mid+1;
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
}
