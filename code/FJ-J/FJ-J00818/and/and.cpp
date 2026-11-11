#include <bits/stdc++.h>
using namespace std;
int n,m,cc,ma;
long long a[200005],ans;
bool bb=1;
bool ch(long long x){
	cc=0;
	while(x){
		if(x&1)return 1;
		x/=2;
		cc++;
	}
	return 0;
}
bool cmp(long long x,long long y){
	bool cx=ch(x);
	int ccx=cc;
	bool cy=ch(y);
	int ccy=cc;
	if(cx!=cy){
		return cx>cy;
	}
	if(cx)return x>y;
	if(max(ccx,ccy)<=ma)return x>y;
	if(ccx>ma)return 0;
	else return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(ch(a[i]))ma=max(ma,cc);
		else bb=0;
	}
	sort(a+1,a+n+1,cmp);
	long long sum=0;

			for(int i=1;i<=n-m+1;i++){
	ans=a[i];
	for(int j=i+1;j<=i+m-1;j++){
		ans=(ans&a[j]); 
	}
	sum=max(sum,ans);
	}
	

	printf("%d",sum);
	return 0;
}
