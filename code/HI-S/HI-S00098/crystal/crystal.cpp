#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=-1;
int a[500005];
int b[500005];
bool check(int x){
	long long sum=0;
	for(int i=1;i+x-1<=n;i++){
		int j=i+x-1;
		sum=(a[j]*x)-(b[j]-b[i-1]);
		if(sum<=m){
			return true;	
		}
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	b[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)==true){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans; 
	return 0;
}
