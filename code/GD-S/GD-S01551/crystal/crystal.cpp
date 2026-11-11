#include<iostream>
#include<algorithm>
using namespace std;
long long n,m;
long long a[500005],d[500005];
int mx1=1;
bool pd(int x,int y){
	return (1ll*(y-x))*a[y]-(d[y-1]-d[x-1])<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		int l=1,r=i,mid,l1=1,r1=i;
		while(l<r){
			mid=(l+r)/2;
			if(pd(mid,i)){
				r=mid;
			}else{
				l=mid;
			}
			if(l1==l&&r1==r){
				break;
			}
			l1=l,r1=r;
		}
		mx1=max(i-r+1,mx1);
	}
	cout<<mx1;
	return 0;
}
