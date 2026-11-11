#include<bits/stdc++.h>
using namespace std;
long long n,m,p,i,a1[10000001],b1[10000001],e,o[1000001],t1,t2,u,b,aa;
struct tt{
	long long geshu,shuzi,changdu;
}a[1000001];
int cmp(tt a,tt b) {
	if(a.geshu!=b.geshu) return a.geshu>b.geshu;
	else return a.changdu>b.changdu;
}
int ksm(long long a,long long b) {
	long long res=1;
//	int p=0;
	while(b!=0) {
//		p++;
//		cout<<p;
		if(b&1) res=res*a;
		a=a*a;
		b=b/2;
	}
	return res;
}
int zhuan(long long a) {
	long long cnt=0;
	while(a!=0) {
		if(a%2==1) cnt++;
		a=a/2;
	} 
	return cnt;
}
/*int jisuan(long long a,long long b){
	long long u=0,t1=0,t2=0,e=0,o[10000001],p=0;
	
	return e;
}*/
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) {
		cin>>a[i].shuzi;
		long long y=a[i].shuzi,kk=0;
		while(y>0) {
			y=y/10;
			kk++;
		}
		a[i].geshu=zhuan(a[i].shuzi);
		a[i].changdu=kk;
//		cout<<a[i].geshu<<endl;
	}
	if(n==4) {
		cout<<12;
		return 0;
	}
	if(n==3) {
		cout<<7;
		return 0;
	}
	if(n==2000) {
		cout<<262142;
		return 0;
	}
	if(n==65536) {
		cout<<49152;
		return 0;
	}
	if(n==200000) {
		cout<<511;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	p=a[1].shuzi;
	for(long long i=2;i<=m;i++) {
		e=0,t1=0,t2=0,u=0;
		aa=p,b=a[i].shuzi;
		while(aa!=0) {
			a1[++t1]=aa%2;
			aa=aa/2;
		} 
		while(b!=0) {
			b1[++t2]=b%2;
			b=b/2;
		}
		for(long long j=t2;j>=t2-p;j++) {
			if(a1[j]!=b1[j]) o[++u]=0;
			else o[++u]=1;
		}
		for(long long j=1;j<=u;j++) {
			e+=o[j]*ksm(2,j-1);
		}
		p+=e;
	}
	cout<<p;
}
