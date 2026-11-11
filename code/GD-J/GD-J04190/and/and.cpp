#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll ans,a[200005];
mt19937 rnd(time(0));
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
		cout<<ans;
		return 0;
	}
	uniform_int_distribution<int>s1(1,m),s2(m+1,n); 
	for(int i=1;i<=4e6;i++){
		int x=s1(rnd),y=s2(rnd);
		swap(a[x],a[y]);
		ll res=a[1];
		for(int i=2;i<=m;i++)res&=a[i];
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}
