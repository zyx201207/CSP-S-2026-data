#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m;
ll b[N];
ll a[N];

bool cheak(int x){
	for(int i=x;i<=n;i++)
		if(b[i]-b[i-x+1]<=m)
			return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
		b[i]=b[i-1]+(a[i]-a[i-1]);
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(cheak(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}