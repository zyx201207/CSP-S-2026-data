#include<bits/stdc++.h>
#define ll long long
#define _i __int128
#define N 500005
using namespace std;
ll n,m;
ll a[N],pre[N],cf[N];
ll ans=0;
bool cmp(ll a,ll b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n,cmp);
	if(n<=5000){
		for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
		
	
		for(ll i=1;i<=n;i++)
			cf[i]=(i-1)*a[i]-pre[i-1];
	
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=i;j++){
				ll val=(i-j)*a[i]-pre[i-1]+pre[j-1];
				if(val<=m)ans=max(ans,i-j+1);
			}
		cout<<ans;
	}
	else{
		
		int pot=0;
		for(int i=1;i<=n;i++)
			pre[i]=pre[i-1]+a[i];
		for(int i=1;i<=n;i++){
			
			if(pre[i-1]>m){pot=i-1;break;}
		}
		cout<<pot;
	}
	return 0;
}

