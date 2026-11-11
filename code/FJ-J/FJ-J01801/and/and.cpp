#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
ll ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<ll>());
	for(int i=1;i<=n;i++){
		if((a[i]&(a[i]+1))==0&&f==0){
			ans=a[i];//2^n-1
			f=1;
		}
	}
	if(f==0){
		ans=a[n];
	}
	for(int i=1;i<=n;i++){
		ans&=a[i];
		m--;
		if(!m){
			cout<<ans;
			break;
		}
	}
	return 0;
}
/*
5 3
31 3 1 15 7
*/
//o_O
