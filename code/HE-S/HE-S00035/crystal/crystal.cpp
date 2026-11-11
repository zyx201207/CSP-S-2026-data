#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,sum[500007];
int a[5000007];
bool chk(int i,int x){
	int al=a[i]*(i-x+1);
	int hv=sum[i]-sum[x-1];
	int nd=al-hv;
	if(nd>m)return 0;
	return 1;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;i++){
		int l=1,r=i,ls=0;
		while(l<r){
			int mid=(l+r)>>1;
			if(chk(i,mid))
				r=mid;
			else l=mid+1; 
		}
		if(l==0)
			r=0xffffffff;
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}
