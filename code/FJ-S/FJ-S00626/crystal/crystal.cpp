#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int n;
ll m;
const int N=5e5+5;
ll pre[N],a[N];

bool ck(int x){
	for(int i=x;i<=n;++i){
		if(m+pre[i]-pre[i-x]>=a[i]*x)return 1;
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		pre[i]=pre[i-1]+a[i];
	}
	
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=l+((r-l+1)>>1);
		if(ck(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
