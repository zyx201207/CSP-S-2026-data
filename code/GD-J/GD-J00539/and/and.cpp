#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define un unsigned
int n,m;
un ll a[200005],ans=0;

un ll anx(int x,un ll k,int ci,int la){
	for(int i=1;i<=n;i++)
	{
		if(x==i){
			continue;
		}
		else{
			k=k&a[i];
		}
	}
	if(ci==0)	return k;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(a[i],ans);
		}
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				un ll x=a[i]&a[j];
				ans=max(ans,x);
			}
		}
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
	}
	else if(m==n-1){
		sort(a+1,a+n+1);
		ans=a[2];
		for(int i=3;i<=n;i++){
			ans=ans&a[i];
		}
	}
	else{
		for(int i=1;i<=n;i++){
			ll an=a[i];
			an=anx(i,an,m-1,i);
		}
	}
	cout<<ans;
	return 0;
}
