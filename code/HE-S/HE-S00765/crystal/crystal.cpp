#include<bits/stdc++.h>//100
using namespace std;
int n,m,a[500005],b[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]+(i-2)*(a[i]-a[i-1])+a[i]-a[i-1];
		int l=-1,r=i,mid;
		while(l+1!=r){
			mid=(l+r)/2;
			if(b[i]-b[mid+1]-(mid)*(a[i]-a[mid+1])<=m){
				r=mid;
			}
			else{
				l=mid;
			}
		}
//		cout<<mid<<' '<<i<<'\n';
		ans=max(ans,i-r);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
