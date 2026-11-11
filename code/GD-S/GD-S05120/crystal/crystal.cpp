#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=0x3f3f3f3f3f3f3f3fLL;
const int N=5e5+5;
int n,m;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int ans=1;
	int sum=0;
	for(int i=2;i<=n;i++){
		int j;
		for(j=1;j<i;j++){
			sum+=a[i]-a[j];
			if(sum>m)break;
			a[j]=a[i];
		}
		if(j==i)ans++;
		if(sum>m)break;
	}
	cout<<ans<<"\n";
	return 0;
} 
