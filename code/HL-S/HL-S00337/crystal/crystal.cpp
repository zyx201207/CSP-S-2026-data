#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
ll a[500005];
ll cha[500005];
ll ji=0,ans=0,t=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;ll m;
	cin>>n >>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cha[i]=a[i]-a[i-1];
	}
//	for(int i=1;i<=n;i++){
		int y=0;
		for(int j=1;j<=n;j++){
			if(ji+y*cha[j]>m)break;
			ji+=y*cha[j];
//			cout<<ji<<endl;
			ans++;y++;
		}
		t=max(t,ans);
		ans=0;ji=0;
//	}
	cout<<t<<endl;
	return 0;
}

