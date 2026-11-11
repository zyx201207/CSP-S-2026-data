#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
//ll abss(ll h,ll g){
//	if(h<0){
//		h=-h;
//	}
//	if(g<0){
//		g=-g;
//	}
//	ll f=h-g;
//	if(f<0){
//		return -f;
//	}
//	return f;
//}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,ans=0,sum=0,ps=1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int i=0;
	while(1){
		if(sum+abs(a[i]-a[i+1])*ps>m){
			ans=max(ans,ps);
			sum=0;
			ps=1;
		}
		else{
			sum+=abs(a[i]-a[i+1])*ps;
			ps++;
			i+=1;
		}
		if(ans>n-i||i>=n-1){
			break;
		}		
	}
	cout<<ans;
	return 0;
}

