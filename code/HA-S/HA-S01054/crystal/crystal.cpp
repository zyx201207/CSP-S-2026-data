#include<bits/stdc++.h>
using namespace std;
long long m,n,ans=1; 
long long a[5000005];


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.ans","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;//wsSB
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int r,l,m1;
	r=2;
	for(int i=1;i<n;i++){
		ans++;r++;
		m1=m;
		m-=i*abs(a[r]-a[r-1]);
		if(m1==m) ans--;
		if(a[r]-a[r-1]==0){
			ans++;
		} 
		if(m<=0) break;
	}
	cout<<ans<<endl;
	return 0;
}

