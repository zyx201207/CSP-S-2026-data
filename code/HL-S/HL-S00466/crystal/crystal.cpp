#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N];
int diff[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;cin>>n>>m;
	bool flag1=true;
	bool flag2=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)flag1=false;
	}
	for(int i=2;i<=n-1;i++){
		if(a[i]-a[i-1]!=a[i+1]-a[i])flag2=false;
	}
	if(flag1){
		int ans=floor((-1.0+sqrt(1+8.0*m))/2)+1;
		cout<<ans;
		return 0;
	}
	if(flag2){
		int d=a[2]-a[1];
		int ans=floor((-1.0+sqrt(1+(8.0*m/d)))/2)+1;
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		diff[i]=a[i]-a[i-1];
	}
	//baoli
	int ans=0;
	for(int i=1;i<=n;i++){
		int sum=0;int qian=1;
		int res=1;
		for(int j=i+1;j<=n;j++){
			sum+=qian*diff[j];
			qian++;
			if(sum<=m){
				res++,ans=max(ans,res);
			}
			else break;
		}
	}
	cout<<ans;
	return 0;
}