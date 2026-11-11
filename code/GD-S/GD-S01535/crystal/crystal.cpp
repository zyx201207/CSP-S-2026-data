#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000005],pre[2000005];
int mx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=0,r=i-1,mid;
		while(l<=r){
			mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(pre[i]-pre[mid])>m)l=mid+1;
			else r=mid-1;
		}
		mx=max(mx,i-mid);
	}
	cout<<mx;
	return 0;
}
