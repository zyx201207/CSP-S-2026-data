#include<bits/stdc++.h>
using namespace std;
long long n,m,x,maxn,l,r,d;
bool f,f1;
long long a[500005];
void check(long long p){
	int t=lower_bound(a+1,a+n+1,p)-a,s=0,f=m;
	int j=t;
	while(a[j]<=p&&j<=n) j++;
	t=j-1;
	for(int i=t;i>=1;i--){
		if(f>=p-a[i]&&p>=a[i]){
			f-=p-a[i];
			s++;
		}
		else break;
	}
	if(maxn<s) maxn=s;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%lld%lld",&a[1],&a[2]);
	if(a[1]!=1||a[2]!=2) f=1;
	d=a[2]-a[1];
	for(long long i=3;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i) f=1;
		if(a[i]-a[i-1]!=d) f1=1;
		x+=a[i];
		l=min(l,a[i]);
	}
	if(f==0){
		int t=m,cnt=1;
		while(t-cnt>=0) t-=cnt++;
		cout<<cnt;
		exit(0);
	}
	if(f1==0){
		int t=m/d,cnt=1;
		while(t-cnt>=0) t-=cnt++;
		cout<<cnt;
		exit(0);
	}
	sort(a+1,a+n+1);
	r=a[n];
	for(long long i=l;i<=r;i++) check(i);
	printf("%lld",maxn);
}

