//贵阳市第三实验中学 梁佑琳 GZ-S00243
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500005];
bool cmp(ll a,ll b){
	return a<=b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	ll l=0,r=n-1,minn=-1e9,mid=(l+r)/2;
	while(l<=r){
		ll s=1,t=0;
		ll mid=(l+r)/2;
		for(ll i=mid-1;i>=0;i--){
			t+=a[mid]-a[i];
			if(t<=m){
				s++;
			}
		}
		if(s>=minn){minn=s;l++;}
		else{r--;}
	}
	cout<<minn<<endl;
	return 0;
}
