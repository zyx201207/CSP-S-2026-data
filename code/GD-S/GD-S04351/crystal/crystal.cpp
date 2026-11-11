#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N];
int d[N],ans=-1,f[N],sum[N];
bool flag=false;
bool check(int s,int x){
	int res;
	if(s==1)res=f[x];
	else res=f[x]-f[s]-(s-1)*(a[x]-a[s]);
	if(res<=m)return true;
	else return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
		if(d[i]!=d[i-1])flag=true;
	} 
	if(!flag){
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+i;
		}
		int l=1,r=n;
		while(l<=r){
			int mid=(l+r)/2;
			if(sum[mid-1]*d[1]<=m)l=mid+1;
			else r=mid-1;
		}
		cout<<l-1<<endl;
	}else{
		f[1]=0;
		for(int i=2;i<=n;i++){
			f[i]=f[i-1]+(i-1)*d[i];
		}
		for(int i=1;i<n;i++){
			int l=i,r=n;
			while(l<=r){
				int mid=(l+r)/2;
				if(check(i,mid))l=mid+1;
				else r=mid-1;
			}
			ans=max(ans,l-i);		
		}
		cout<<ans<<endl;		
	}
	return 0;
}
