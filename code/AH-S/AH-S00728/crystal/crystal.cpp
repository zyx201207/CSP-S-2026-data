#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=5e5+10;
ll a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;ll m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];int Ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=i;
		while(l<=r){int mid=l+r>>1;
			if(1ll*(i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m)r=mid-1,ans=mid;
			else l=mid+1;
		}Ans=max(Ans,i-ans+1);
	}cout<<Ans;
	return 0;
}

