#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long n,m,a[N],cnt,ans,k,l,r,ii;
long long check(int mid){
	long long res=0;
	for(int j=mid;j>=1;j--)res+=a[mid]-a[j];
	return res;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	l=1,r=n,ans=1;
	while(l<r){
		if(ii>50)break;
		int mid=(l+r)/2;
		if(check(mid)>m)r=mid-1;
		else l=mid,ans=mid;
		ii++;
	}
	cout<<ans;
} 
