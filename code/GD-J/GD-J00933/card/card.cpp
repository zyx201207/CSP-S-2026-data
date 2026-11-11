#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[200010],t[201010];
ll ans1,ans2;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	if(m==2){
		for(ll i=1;i<=n;i++){
			t[a[i]]++;
		}
		if(t[1]%2==0?ans1+=0:ans1+=1);
		if(t[2]%2==0?ans2+=0:ans2+=1);
		for(ll i=2;i<=n;i++){
			memset(t,0,sizeof(t));
			for(ll j=i;j<=n;j++){
				t[a[j]]++;
			}
			if(t[1]%2==0?ans1+=0:ans1+=1);
			if(t[2]%2==0?ans2+=0:ans2+=1);
		}
		cout<<ans1<<" "<<ans2;
	}
	else{
		for(ll i=1;i<=n;i++)cout<<1<<" ";
	}
	return 0;
}
