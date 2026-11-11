#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5*1e5+100;

ll n,m;
ll num[N];
map<ll,ll> mp;
ll ans;
ll s;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	int flag=0;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		mp[num[i]]++;
		ans=max(ans,mp[num[i]]);
	} 
	sort(num+1,num+1+n);
	for(int i=2;i<=n;i++){
		if(num[i]==num[i-1]) continue;
		ll x=num[i],t=m,cnt=0;
		int j=i-1;
		while(true){
			if(j==0||t==0) break;
			ll y=num[j];
			if(abs(x-y)<=t) t-=abs(x-y),cnt++;
			else t=0;
			j--;
			s++;
		}
		ans=max(ans,cnt+mp[num[i]]);
	}
	
	cout<<ans;
	return 0;
}

