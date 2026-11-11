#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=5e5+7;
ll num[MAXN],sum[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m,ans=0,l,r,mid,dx;
	bool flag;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	sort(num+1,num+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+num[i];
	l=0,r=n;
	while(r>l){
		mid=(l+r)>>1;
		flag=0;
		for(int i=mid;i<=n;i++){
			dx=(sum[i]-sum[i-1])*mid-(sum[i]-sum[i-mid]);
			if(dx<=m){
				flag=1;
				break;
			}
		}
		if(flag==0)r=mid;
		else {
			l=mid+1;
			ans=max(ans,mid);
		}
	}
	cout<<ans;
}
