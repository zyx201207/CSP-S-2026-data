#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+4;
ll n,m,ans=1,a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	ll id=1;
	for(int i=2;i<=n;i++){
		while(a[i]*(i-id+1)-(s[i]-s[id-1])>m){
			id++;
		}
		ans=max(ans,i-id+1);
	}
	cout<<ans;
	return 0;
}
/*
X - SLASH
*/
