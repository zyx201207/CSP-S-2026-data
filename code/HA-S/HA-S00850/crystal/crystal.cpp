#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500006],s[500005],cnt;

int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	if(n>5000){
		int b=a[2]-a[1];
		int c=m/b;
		int p=1;
		cnt=1;
		while(c>=p){
			c-=p;
			p++;
			cnt++;
		}
	}
	else {
	for(ll l=1;l<=n;l++){
		for(ll r=l;r<=n;r++){
			int a1=a[r]*(r-l+1)-(s[r]-s[l-1]);
			if(a1<=m)cnt=max(cnt,r-l+1);
			else if(a1>m)break;
		}
	}
	}
	cout<<cnt;
}
