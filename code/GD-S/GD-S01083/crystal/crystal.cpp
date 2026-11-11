#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
ll a[500010];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	ll rp=a[2]-a[1];
	bool flag=1;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=rp){
			flag=0;
			break;
		}
	}
	if(flag){
		int qwq=(n+1)/2;
		int ans1=0;
		ll cnt1=0;
		int l=qwq-1,r=qwq+1;
		while(l>=1&&r<=n){
			cnt1+=rp;
			if(cnt1>m){
				cnt1-=rp;
				break;
			}
			ans1++;
			l--;
			cnt1+=rp;
			if(cnt1>m){
				cnt1-=rp;
				break;
			}
			ans1++;
			r++;
		}
		cout<<ans1;
		return 0;
	}
	
	sort(a+1,a+n+1,cmp);
	int l=1,ans=0;
	while(l<=n){
		ll cnt=0;
		int i;
		for(i=l+1;i<=n;i++){
			cnt+=a[l]-a[i];
			if(cnt>m){
				cnt-=a[l]-a[i];
				break;
			}
		}
		ans=max(ans,i-l);
		l++;
	}
	cout<<ans;
	return 0;
} 
