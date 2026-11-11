#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
ll a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("dma.in","r",stdin);
//	freopen("dma.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	ll l=1,r=1,ans=1;
	while(l<=n&&r<=n){
		if(r<l)r=l;
		ans=max(ans,r-l+1);
		if((r+1-l+1)*a[r+1]<=m+s[r+1]-s[l-1]){
			r++;
		}else{
			l++;
		}
	}
	cout<<ans<<"\n";
	return 0; 
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

2 12
9 6 

*/
