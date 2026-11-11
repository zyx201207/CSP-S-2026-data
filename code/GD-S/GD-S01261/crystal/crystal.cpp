#include<bits/stdc++.h>
using namespace std;
long long a[500001],q[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	int ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		q[i]=q[i-1]+a[i];
	}
	int l=1;
	for(int i=2;i<=n;++i){
		while(a[i]*(i-l)-(q[i-1]-q[l-1])>m)
			++l;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
