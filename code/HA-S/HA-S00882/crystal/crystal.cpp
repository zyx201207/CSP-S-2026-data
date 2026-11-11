#include<bits/stdc++.h>
using namespace std;
struct A{
	int num;
	int cnt;
	long long p;
//	
//	bool operator < (const A& Other__){
//		return .<Other__.
//	}
//	bool operator > (const A& Other__){
//		return .>Other__.
//	}
}b[500101];
int read_i(){
	char re;
	int r=1;
	re=getchar();
	while(re>'9'||re<'0'){
		if(re=='-')r=-1;
		re=getchar();
	}
	int x=0;
	while(re>='0'&&re<='9'){
		x*=10;
		x+=re-'0';
		re=getchar();
	}
	return x*r;
}
long long read_ll(){
	char re;
	int r=1;
	re=getchar();
	while(re>'9'||re<'0'){
		if(re=='-')r=-1;
		re=getchar();
	}
	long long x=0;
	while(re>='0'&&re<='9'){
		x*=10;
		x+=re-'0';
		re=getchar();
	}
	long long qp=x*r;
	return qp;
}
int n;
long long m;
long long a[500101];
long long c[500101];
long long d[500101];
long long e[500101];
bool check(int t,int k){
	long long pq=k-t;
	
	long long tr=pq*d[k]-e[k-1]+e[t-1];
//	cout<<tr<<"\n";
	
	if(tr>m)return false;
	return true;
}

long long dp=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read_i();
	m=read_ll();
	for(int i=1;i<=n;i++){
		a[i]=read_ll();
	}
	sort(a+1,a+n+1);
	int sum=1;
	b[sum].p=a[1];
	b[sum].num=1;
	b[sum].cnt=1;
	d[1]=0;
	for(int i=2;i<=n;i++){
		if(a[i]==b[sum].p){
			b[sum].cnt++;
		}else{
			sum++;
			b[sum].num=i;
			c[sum]=c[sum-1]+b[sum-1].cnt;
//			cout<<sum<<":"<<b[sum].num<<" "<<a[i]<<"\n";
			b[sum].cnt=1;
			b[sum].p=a[i];
		}
		d[i]=d[i-1]+a[i]-a[i-1];
		e[i]=e[i-1]+d[i];
//		cout<<"i="<<i<<":"<<d[i]<<"\n";
	}
	int maxn=b[1].cnt;
	for(int i=2;i<=sum;i++){
		int l=1,r=b[i].num;
		int mid;
		while(l<=r){
			mid=(l+r)/2;
			if(check(mid,b[i].num)){
				r=mid-1;
			}else{
				l=mid+1;
			}
//			cout<<"mid:"<<mid<<" "<<b[i].num<<" "<<d[mid]<<" "<<d[b[i].num]<<"\n";
		}
//		cout<<maxn<<" "<<l<<" "<<r<<" "<<b[i].num-1<<" "<<"\n";
//		if(b[i].cnt+b[i].num-mid==315829){
//			cout<<b[i].num<<" "<<mid<<" "<<b[i].cnt<<" "<<e[b[i].num]<<" "<<e[b[i].cnt]<<"\n";
//		}
		maxn=max(maxn,b[i].cnt+b[i].num-l);
	}
	printf("%d\n",maxn);
//	printf("%lld",dp);
	return 0;
}
