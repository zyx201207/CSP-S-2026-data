#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll a[N],b[N];
unordered_map<ll,int> mp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,ans=0;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		mp[a[i]]++;
		ans=max(ans,mp[a[i]]);
	}
	sort(b+1,b+n+1);
	int len=unique(b+1,b+n+1)-b-1;
	int j=1,tot=0,cnt=mp[b[1]];
	for(int i=2;i<=len;i++){
		ll c=(b[i]-b[i-1])*cnt;
		tot+=c;
		cnt+=mp[b[i]];
		if(tot>m){
			while(tot>m){
				tot-=mp[b[j]]*(b[i]-b[j]);
				cnt-=mp[b[j]];
				j++;
			}
			ll h=(m-tot)/(b[i]-b[j-1]);
			if(h>0){
				j--;
				cnt+=h;
				tot+=h*(b[i]-b[j]);
				mp[b[j]]=h;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<"\n";
	return 0;
}
