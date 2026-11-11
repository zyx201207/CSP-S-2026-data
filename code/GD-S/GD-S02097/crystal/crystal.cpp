#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+8;
ll a[N];
int main(){
	//system("fc /w crystal3.ans crystal3.out");
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,u,ans=0;
	cin>>n>>u;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ll cnt=1;
	for(ll i=1;i<n;i++){
		if(a[i]==a[i-1]){
			cnt++;
		}else{
			ans=max(ans,cnt);
			cnt=1;
		}
	}
	ans=max(ans,cnt);
	cnt=0;
	ll l=0,ans2=0;
	for(ll i=0;i<n;i++){
		cnt+=a[i]; 
		if(u-((i-l+1)*a[i]-cnt)>=0){
			ans2++;
		}else{
			ans2++;
			while(u-((i-l+1)*a[i]-cnt)<0){
				cnt-=a[l];
				l++;
				ans2--;
			}
		}
		ans=max(ans,ans2);
	}
	cout<<ans;
	return 0;
} 
