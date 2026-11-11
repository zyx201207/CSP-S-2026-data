#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int n,cnt;
long long m,a[MAXN],b[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(((long long)i-(long long)mid)*a[i]-(b[i-1]-b[mid-1])<=m){
				ans=mid;
				r=mid-1;
			}else l=mid+1;
		}
		cnt=max(cnt,i-ans+1);
	}
	cout<<cnt;
	return 0;
}
