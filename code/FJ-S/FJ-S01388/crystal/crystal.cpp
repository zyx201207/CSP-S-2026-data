#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010],b[500010],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;i++){
		long long h=a[i];
		long long l=1,r=i,mid;
		while(l<=r){
			mid=(l+r)/2;
			long long need=(i-mid+1)*h-(b[i]-b[mid-1]);
			if(need<=m){
				ans=max(ans,i-mid+1);
				r=mid-1;
			}else l=mid+1;
		}
	}
	cout<<ans;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
