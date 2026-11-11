#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string s;
const ll N=2e5+10;
ll n;
struct zh{
	ll sh;
	char ch;
};
zh aa[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll a;char b;
		cin>>a>>b;
		aa[i].sh=a;
		aa[i].ch=b;
	}
	ll l=1,r=n,ans=0;
	while(l<=r){
		if(aa[l].sh>aa[r].sh){
			aa[l].sh-=aa[r].sh;
			if(aa[l].ch!=aa[r].ch)ans+=aa[r].sh;
			r--;
		}else{
			aa[r].sh-=aa[l].sh;
			if(aa[l].ch!=aa[r].ch)ans+=aa[l].sh;
			l++;
		}
		//cout<<ans<<" ";
	}
	cout<<ans;
	
	return 0;
}
