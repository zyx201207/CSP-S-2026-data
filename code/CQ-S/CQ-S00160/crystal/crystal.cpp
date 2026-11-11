//I love you,Takanashi Hoshino.
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int d[500005];
int d_sum[500005];
bool check(int x){
	for(int i=x;i<=n;i++){
		if(d[i]*(x-1)-(d_sum[i-1]-d_sum[i-x+1-1])<=m)return 1;
		//d[i]-d[i-1]+d[i]-d[i-2]+...+d[i]-d[i-x+1]
		//=d[i]*(x-1)-(d[i-1]+d[i-2]+...+d[i-x+1])
		//=d[i]*(x-1)-(d_sum[i-1]-d_sum[i-x+1-1])
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int maxa=a[n],mina=a[1];
	for(int i=1;i<=n;i++)d[i]=a[i]-a[1];
	for(int i=1;i<=n;i++)d_sum[i]=d_sum[i-1]+d[i];
	int l=0,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<r<<"\n";
	/*
	if(0){
		int ans=0;
		for(int k=mina;k<=maxa;k++){
			vector<int>sum;sum.clear();
			for(int i=1;i<=n;i++)if(k>=a[i])sum.push_back(k-a[i]);
			sort(sum.begin(),sum.end());
//			if(sum[0]<0){
//				cout<<"k="<<k<<"\n";
//				return 0;
//			}
			for(int i=0,tot=0;i<sum.size();i++){
				if(tot+sum[i]>m){
					ans=max(ans,i+1);
					break;
				}
				tot+=sum[i];
			}
			if(ans==3846){
				cout<<k<<"\n";
				return 0;
			}
//			if(ans==3){
//				cout<<k<<"\n";
//				for(int i=0;i<n;i++)cout<<sum[i]<<" ";cout<<"\n";
//				for(int i=0,tot=0;i<n&&tot+sum[i]<=m;i++)tot+=sum[i],cout<<i<<" ";cout<<"\n";
//			}
		}
		cout<<ans<<"\n";
	}
	else {
		int l=0,r=n;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid))l=mid+1;
			else r=mid-1;
		}
		cout<<r<<"\n";
	}
	*/
	return 0;
}

/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/



