#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,k;
long long a[N],b[N],c[N];
int max_=-1;
int sum;
bool fa=true,fb=true;
int aa;
void ff(long long x){
	for(long long i=1;i<=x;i++){
		c[i]-=b[x];
	}
	return;
}
void f1(){
	max_=0;
	long long kk=1;
	while(1){
		if(kk==n) break;
		if(m-kk<0) {
			break;
		}
		else {
			m-=kk;
			kk+=1;
		}
	}
	cout<<kk<<endl;
	return;
}
void f2(){
	max_=0;
	long long kk=aa;
	while(1){
		if(kk==n) break;
		if(m-kk<0) {
			break;
		}
		else {
			m-=kk;
			kk+=aa;
		}
	}
	cout<<kk<<endl;
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	k=m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		aa=a[2]-a[1];
		if(i>=2 and a[i]!=i) fa=false;
		if(i>=2 and a[i]-a[i-1]!=aa) fb=false;
	}
	if(fa==true) {
		f1();
		return 0;
	}
	if(fb==true) {
		f2();
		return 0;
	}
	sort(a+1,a+n+1);
	b[n]=0;
	for(long long i=n-1;i>=1;i--){
		b[i]=a[i+1]-a[i];
	}
	c[n]=0;
	for(long long i=n-1;i>=1;i--){
		c[i]=c[i+1]+b[i];
	}
	for(long long i=n;i>=1;i--){
		k=m;
		sum=0;
		long long j=i;
		while(1){
			if(j==0) break;
			if(c[j]<=k) {
				k-=c[j];
				sum+=1;
				j--;
			}
			else break;
		}
		max_=max(max_,sum);
		ff(i-1);
	}
	cout<<max_<<endl;
//	for(int i=1;i<=n;i++) cout<<c[i]<<" ";
//	cout<<endl;
	return 0;
}
