#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],k[500001],kk[500001],maxx=1,mm,h,hh;
map<long long,long long> mp;
bool cmp(long long a,long long b){
	return a<=b;
}
bool check(long long x){
	long long nmm=(x*x+x)/2*hh;
	if(nmm<=m)return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++){
		k[i-1]=a[i]-a[i-1];
		mp[k[i-1]]++;
		hh=k[i-1];
	}
	if(mp.size()==1){
		long long l=1,r=(n-1)/hh,mid,ans=0;
		while(l<=r){
			mid=(l+r)/2;
			if(check(mid)){
				l=mid+1;
				ans=mid;
			}
			else r=mid-1;
		}
		cout<<ans+1;
		return 0;
	}
	for(int i=1;i<n;i++)kk[i]=k[i]+kk[i-1];
	for(int i=2;i<=n;i++){
		mm=0,h=1;
		for(int j=i-1;j>0;j--){
			mm+=(kk[i-1]-kk[j-1]);
			if(mm<=m)h++;
			else break;
		}
		maxx=max(maxx,h);
	}
	cout<<maxx;
	return 0; 
} 
