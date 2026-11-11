//GZ-J00123 »ÆºÆÈ» 
#include<bits/stdc++.h>
#define ll long long
#define mll map<ll,ll>
#define pll pair<ll,ll>
using namespace std;

void fx(){
	ll n ,m;cin>>n>>m;
	vector<ll>a(n+1,0);
	for(ll i=n;i>=1;i--)cin>>a[i];
	vector<ll>ans(m+1,0);
	mll lst;
	map<ll,mll>huisu;
	for(ll i=1;i<=n;i++){
		if(lst[a[i]]){
			lst=huisu[lst[a[i]]];
		}
		lst[a[i]]=i;
		huisu[i]=lst;
		for(ll j=1;j<=m;j++)ans[j]+=(lst[j]!=0);
	}
	for(ll i=1;i<=m;i++)cout<<ans[i]<<" ";
	cout<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll t=1;
	while(t--)fx();
}
