#include<bits/stdc++.h>
using namespace std;
const int N=500010;
long long n,m,a[N],sa[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)  sa[i]=sa[i-1]+a[i];
	long long ans=1;
	for(int i=2;i<=n;i++){
		long long l=1,r=i;
		while(l<=r){
			long long mid=(l+r)/2;
			long long tmp=(i*1ll-mid+1ll)*a[i]-sa[i]+sa[mid-1];
		//	cout<<i<<" "<<mid<<" "<<tmp<<" "<<i-mid+1<<endl;
			if(tmp<=m){
		//		cout<<i-mid+1<<" "<<ans<<" pr"<<endl; 
				ans=max(ans,i*1ll-mid+1);
				r=mid-1ll;
			}
			else l=mid+1ll;
		}
	}
	cout<<ans;
	return 0;
} 

/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
