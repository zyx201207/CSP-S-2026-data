#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500010;
ll n,m,a[N],ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==1){//只有一个无法合成 特判 
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=n,r=n;//左右指针 
	ll sum=0,cnt=0;
	bool p=1;
	while(1){//双指针
		sum+=a[r]-a[--l];
		++cnt;
		if(l==1){
			if(sum>m) cnt--;
			ans=max(ans,cnt+1);
			//cout<<sum<<'a'<<cnt+1<<endl;
			break;
		}
		if(sum>m){
			--cnt;
			//cout<<sum<<'a'<<cnt+1<<'b';
			sum-=(a[r]-a[r-1])*(cnt+1);
			--r;
			ans=max(ans,cnt+1);	
		}
	}
	if(ans>1) cout<<ans;
	else cout<<0;
	return 0;
}
