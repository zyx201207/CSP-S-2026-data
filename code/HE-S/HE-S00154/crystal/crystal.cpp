#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long m,a[500005],b[500005],c[500005],maxn=-1;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp); 
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			b[i]=a[j]-a[i];
		}
		for(int i=j;i<=n;i++){
			c[i]=c[i-1]+b[i];
		}
		int l=j,r=n;
		while(l<r){
			int mid=(l+r)/2;
			if(c[mid]<m){
				l=mid+1;
			}
			else if(c[mid]>m){
				r=mid-1;
			}
		}
		int t=r-j+1;
		if(t>maxn){
			maxn=t;
		}
	}
	cout<<maxn;
	return 0;
}
