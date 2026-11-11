#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans;
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
	long long j=0;
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
		if(a[i]*(i-j)-(b[i]-b[j])>m)j++;
		ans=max(ans,i-j);
	}
	cout<<ans;
	return 0;
}

