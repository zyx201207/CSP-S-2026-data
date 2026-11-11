#include<bits/stdc++.h>

using namespace std;

const int N=5e5+10;
int a[N];
int df[N],sum[N],ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)df[i]=a[i]-a[i-1];
	df[1]=0;
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+df[i];
	for(int l=1;l<=n;l++){
		for(int r=n;r>=l;r--){
			long long cnt=0;
			for(int i=l;i<=r;i++)cnt+=sum[r]-sum[i];
			if(cnt<=m)ans=max(ans,r-l+1);
		}
	}
	cout<<ans;
	
	return 0;
}
