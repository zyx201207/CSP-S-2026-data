#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
struct node{
	long long co;
	int ge;
}d[500010];
long long check(){
	long long ch=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=ch) return -1;
	}
	return ch;
}
long long gs(long long x){
	long long l=1,r=x,mid=(l+r)/2;
	while(l<r){
		mid=(l+r)/2;
		if(mid*(mid+1)/2<=x) l=mid;
		else r=mid-1;
	}
	return l;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	if(n==1){
		cout<<1;
		return 0;
	}
	long long c=check();
	if(c!=-1){
		if(m<c){
			cout<<1;
			return 0;
		}
		long long a=m/c;
		long long b=gs(a);
		cout<<b+1;
		return 0;
	}
	int p=1;
	d[1].co=0;
	d[1].ge=1;
	for(int i=2;i<=n;i++){
		d[i].co=d[i-1].co+(a[i]-a[i-1])*d[i-1].ge;
		while(d[i].co>m){
			d[i].co=d[i].co-(a[i]-a[p]);
			p++;
		}
		d[i].ge=i-p+1;
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,d[i].ge);
	}
	cout<<maxn;
    return 0;
}
