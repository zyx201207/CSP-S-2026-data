#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>

const int N=5e5+10;
int n,ans;
ll m;
ll a[N],sum[N];

bool check(int x,int y){
	ll val=sum[y]-sum[x-1];
	val=(ll)a[y]*(y-x+1)-val;
	return val<=m;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid;
		while(l<r){
			mid=(l+r)>>1;
			if(check(mid,i))r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<"\n";

	return 0;
}

