#include <bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[500001],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long x=1e12,y=-1e12;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		x=min(x,a[i]*1LL);
		y=max(x,a[i]*1LL);
	}
	int i;
	for (i=x;i<=y;i++){
		bool x=true;
		for (int j=1;j<=n;j++){
			b[j]=i-a[j];
		}
		int cnt=m,count=0;
		sort(b+1,b+n+1);
		for (int i=1;i<=n;i++){
			if (b[i]>=0&&cnt>=b[i])cnt-=b[i],count++;
		}
		ans=max(count,ans);
	}
	cout<<ans;
	return 0;
}
