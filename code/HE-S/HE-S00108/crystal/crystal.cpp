#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
bool flaga=1,flagb=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) flaga=0;
		if(i>2){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]) flagb=0;
		}
	}
	sort(a+1,a+n+1);
	if(flaga==1){
		for(int i=1;i<=n;i++){
			if(m<i){
				cout<<i-1;
				return 0;
			}
			m-=i;
		}
	}
	if(flagb==1){
		int ans=1,c=a[2]-a[1];
		for(int i=1;i<=n;i++){
			if(m>=ans*c){
				m-=ans*c;
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1,x=0,y=LLONG_MAX;
		for(int i=1;i<=n-mid+1;i++){
			for(int j=0;j<mid-1;j++){
				x+=a[i+mid-1]-a[i+j];
			}
			y=min(y,x);
			x=0;
		}
		if(y>m) r=mid-1;
		if(y<m) l=mid+1;
		if(y==m){
			cout<<mid;
			return 0;
		}
	}
	cout<<r;
	return 0;
}
