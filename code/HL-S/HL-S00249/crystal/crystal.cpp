#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[500005],b[500005],d[500005];
long long n,m;
bool check(int x){
	int u=0;
	for(int i=x;i<=n;i++){
		long long y=d[i-1]-d[i-x];
		long long h=a[i]*(x-1)-y;
		if(h<=m)return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
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
	int l=1,r=n,u=0,lal=l,lar=r,op=0;
	while(l<r){
		if(op>=50){
			cout<<l;
			return 0;
		}
		int mid=(l+r)/2;
		if(check(mid)==true){
			l=mid;
			if(lal==l&&lar==r){
				op++;
			}
			lal=l;
			u=mid;
		}
		else{
			r=mid-1;
			lar=r;
		}
	}
	cout<<u;
	return 0;
}
