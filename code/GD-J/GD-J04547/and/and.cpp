#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
const int N = 2e5+5;
ll n,m,Max=INT_MIN;
ll a[N],cnt[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	memset(cnt,-0x3f,sizeof(cnt));
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		ll ans=0;
		for(ll i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}
	for(ll i=1;i<=n;i++){
		ll ta=0;
		for(ll j=1;j<=n;j++){
			ta=a[i];
			for(ll k=1;k<=m-1;k++){
				ta&=a[j+k];	
			}
			cnt[i]=max(cnt[i],ta);
			//cout<<ta<<' ';
		}
		//cout<<'\n';
		cnt[i]=max(cnt[i],ta);
	}
	for(ll i=1;i<=n;i++){
		Max=max(Max,cnt[i]);
	}
	cout<<Max;
	return 0;
}

//4 2
//3 5 12 12


//5 3
//31 3 1 15 7

//Trick||Treat!
