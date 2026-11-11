#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,a[700001],qzh[700001],ans=1,l,r,mid,cz;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){qzh[i]=1LL*(i-1)*(a[i]-a[i-1])+qzh[i-1];}
	for(int i=2;i<=n;i++){
		l=1;r=i;
		while(l<r){
			mid=(l+r)/2;
			cz=qzh[i]-qzh[mid]-(mid-1)*(a[i]-a[mid]);
			if(cz<=m)r=mid;
			else l=mid+1;
		}ans=max(ans,i-r+1);
	}cout<<ans;
	return 0;
}
