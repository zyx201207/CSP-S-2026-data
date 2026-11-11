#include<bits/stdc++.h>
using namespace std;
long long n,x,l,mid,f,sum;
long long a[200010];
char c[200010];
int upper(long long x){
	int l=1,r=n;
	while(l<=r){
		int m=(l+r)/2;
		if(a[m]>x) r=m-1;
		else l=m+1;
	}
	return l;
}
int lower(long long x){
	int l=1,r=n;
	while(l<=r){
		int m=(l+r)/2;
		if(a[m]>=x) r=m-1;
		else l=m+1;
	}
	return l;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c[i];
		l+=x;
		a[i]=x+a[i-1];
	}
	mid=l/2;
	if(l%2==1) f=1;
	int k=upper(mid);
	for(int i=1;i<k;i++){
		int xx=l-a[i-1],yy=l-a[i]+1;
		int L=lower(xx),R=lower(yy);
		if(c[L]!=c[i]) sum+=xx-a[L-1];
		if(c[R]!=c[i]&&R!=L) sum+=a[R]-yy+1;
	}
	if(a[k-1]==mid){
		cout<<sum;
		return 0;
	}
	int xx=l-a[k-1],yy=l-mid+1;
	int L=lower(xx),R=lower(yy);
	if(c[L]!=c[k]) sum+=a[L]-xx+1;
	if(c[R]!=c[k]) sum+=yy-a[R-1];
	cout<<sum;
	return 0;
}
