#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,k,ak,bk,ax,bx,u,v,l,r;
bool check(int mid){
	mid--;
	ak=k/2;
	bk=k-ak;
	ax=1+mid+ak-1;
	bx=n-mid-bk+1;
	if(ax+1>=bx) return true;
	int p=(n+1)/2;
	if(min(p-ax,bx-p)>mid) return false;
	p++;
	if(min(p-ax,bx-p)>mid) return false;
	return true;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++) scanf("%d%d",&u,&v);
		if(n==k){
			printf("0\n");
			continue;
		}
		l=1;
		r=n;
		n--;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid)) r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}
