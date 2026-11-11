#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int n,m,a[200005],ans,maxx,as;
bool cmp(int z,int x){return z>x;}
int lx(int k)
{
	int l=m,r=as,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(a[mid]&k)l=mid+1;
		else r=mid-1;
	}
	return mid-1;
}
bool h(int k)
{
	for(int i=1; i<=m; i++)
		if((a[i]&k)==0)return 0;
	return 1;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i];
	as = n;
	for(int i=(1<<30); i; i>>=1){
		sort(a+1,a+1+as,cmp);
		if(h(i)){
			as=lx(i);
			ans|=i;
		}
		for(int j=1; j<=as; j++)
			a[j]&=(i-1);
	}
	cout<<ans;
	return 0;
}
