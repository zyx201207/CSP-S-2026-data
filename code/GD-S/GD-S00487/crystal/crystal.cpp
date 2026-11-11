#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int n,l,r,ma;
ll m,a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];l=0,r=i;
		while(l+1<r){
			int mi=(l+r)>>1;
			if(1ll*(i-mi+1)*a[i]-(b[i]-b[mi-1])<=m)r=mi;
			else l=mi;
		}
		ma=max(ma,i-r+1);
	}
	cout<<ma;
	return 0;
} 
