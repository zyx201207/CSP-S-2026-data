#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct T{
	long long a;
	char c;
} a[N],b[N],c[N];
long long l,n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].a>>a[i].c;
		l+=a[i].a;
	}
	long long x=l/2;
	int len=0,m=0;
	long long sum=0;
	for(int i=1;i<=n;++i){
		if(a[i].a+sum<=x) b[++len]=a[i],sum+=a[i].a;
		else{
			b[++len].c=a[i].c,b[len].a=x-sum;
			a[i].a-=b[len].a;
			a[i].a-=(l&1);
			for(int j=n;j>=i;--j) c[++m]=a[j];
			break;
		}
	}
	int ll=1,rr=1;
	while(ll<=len&&rr<=m){
		long long x=min(b[ll].a,c[rr].a);
		if(b[ll].c!=c[rr].c) ans+=x;
		b[ll].a-=x;
		c[rr].a-=x;
		while(ll<=len&&!b[ll].a)++ll;
		while(rr<=m&&!c[rr].a) ++rr;
	}
	cout<<ans;
	return 0;
}
