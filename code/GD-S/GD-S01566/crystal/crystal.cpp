#include<bits/stdc++.h>
using namespace std;
int n; long long m,s;
long long a[500005],d[500005][500005],dd[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; s+=a[i];
	}
	sort(a+1,a+1+n);
	long long ans=0,sum=0,cnt=0;
	if((a[1]+a[n])*n/2==s){
		for(int i=2;i<=n;i++){
			dd[i]=a[i]-a[1];
		}
		for(int i=2;i<=n;i++){
			sum+=dd[i],ans++;
			if(sum>m) break;
		}
		if(m>=sum) ans++;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			d[i][j]=abs(a[i]-a[j]);
		}
	}
	for(int i=1;i<=n;i++){
		sum=0,cnt=0;
		for(int j=1;j<=i;j++){
			if(sum<=m) cnt++;
			sum+=d[i][j];
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
