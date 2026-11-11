#include<bits/stdc++.h>
using namespace std;
int n,ans=1;
long long a[500005];
unsigned long long t,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1;
	for(int i=2;i<=n;i++){
		t+=(a[i]-a[i-1])*(i-l);
		while(t>m)t-=a[i]-a[l++];
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}

