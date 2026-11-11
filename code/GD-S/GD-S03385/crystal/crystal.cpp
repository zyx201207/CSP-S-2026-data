#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],f[500010],ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int v=0;
	for(int i=1;i<n;i++) f[i]=a[i+1]-a[i];
	for(int i=1;i<n-1;i++) if(f[i]!=f[i+1]) v=1;
	if(v==0){
		int i,sum=0,d=0;
		for(i=1;i<=n;i++){
			sum=sum+f[i];
			d=sum+d;
			if(d>m) break; 
		}
		cout<<i;
		return 0;
	}
//	for(int i=1;i<n;i++) cout<<f[i]<<" ";
	for(int i=2;i<=n;i++){
		int d=0,cnt=0,sum=0;
		for(int j=i-1;j>=1;j--){
			sum=sum+f[j];
			d=sum+d;
			if(d<=m) cnt++;
			else break;
		}
//		cout<<cnt<<" "<<d<<"\n";
		ans=max(cnt,ans);
	}
//	cout<<"\n";
	cout<<ans+1;
	return 0;
} 
