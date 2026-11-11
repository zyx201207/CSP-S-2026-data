#include<bits/stdc++.h>
using namespace std;
#define maxn 500005

int n,m,anss=1;
long long a[maxn],sum[maxn];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=i;
		while(l<=r){
			int mid=l+r>>1;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m){
				r=mid-1;
				ans=mid;
			}else l=mid+1;
		}
		//cout<<ans<<endl;
		anss=max(anss,i-ans+1);
	}
	
	cout<<anss;
	
	return 0;
}
/*
5 10000
1 2 4 8 9
*/
