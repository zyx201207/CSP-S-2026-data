#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,a[N],sum[N],k[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int maxx=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		k[i]=a[i]*(i-1)-sum[i-1];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid;
	    while(l<=r){
	    	mid=(l+r)/2;
	    	if(k[i]-a[i]*(mid-1)+sum[mid-1]>m)l=mid+1;
	    	else r=mid-1; 
		}
		if(k[i]-a[i]*(mid-1)+sum[mid-1]<=m)maxx=max(maxx,i-mid+1);
	}
	cout<<maxx<<endl;
	return 0;
}
