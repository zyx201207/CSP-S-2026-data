#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,a[500005],ans=1,qz[500005];

void search(ll x,ll o){
	ll lt=1,rt=x;
	while(lt<rt){
		ll mid=(lt+rt)>>1;
		if(o*(x-mid+1)+qz[mid-1]-qz[x]<=m)
			rt=mid;
		else
			lt=mid+1;
		
	}
	ans=max(x-rt+1,ans);
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		qz[i]=qz[i-1]+a[i];
	for(int i=n;i>=ans;i--)
		search(i,a[i]);
	cout<<ans;
	return 0;
}
