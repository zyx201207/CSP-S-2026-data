#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,cnt;
long long m;
long long a[N],x[N];
int l,r,mid;
bool check(int i,int mid){
	return (i-mid+1)*a[i]-(x[i]-x[mid-1])<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		x[i]=x[i-1]+a[i];
	}
	for (int i=n;i>=1;i--){
		l=1;
		r=i;
		while(l<=r){
			mid=(l+r)/2;
			if (check(i,mid)){
				r=mid-1;
			}
			else l=mid+1;
		}
		cnt=max(cnt,i-l+1);
	}
	cout<<cnt;
	return 0;
} 
