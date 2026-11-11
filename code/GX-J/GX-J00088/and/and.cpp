#include <iostream>
using namespace std;
long long n,ans;
long long a[200005],b[200005];
long long sum;
int f(long long x,long long s){
	if(x==0){
		return s;
	}
	s=x%2+s*10;
	f(x/2,0);
}
int f2(long long x,long long s){
	if(x==0){
		return s;
	}
	long long w=1;
	for(long long i=1;i<=sum;i++){
		w*=2;
	}
	s+=x%10*w;
	sum--;
	f(x/10,0);
}
int f3(long long x1,long long x2,long long num){
	sum=0;
	x1=f(x1,0);
	x2=f(x2,0);
	while(x1!=0||x2!=0){
		if(x1%10==x2%10&&x1%10==1){
			num=num*10+1;
		}
		else{
			num*=10;
		}
		sum++;
	}
	num=f2(num,0);
	return num;
}
int f4(long long x,long long m){
	if(m==0){
		return x;
	}
	long long j;
	for(long long i=1;i<=n;i++){
		if(b[i]==1){
			continue;
		}
		if(x<f3(x,a[i],0)){
			x=f3(x,a[i],0);
			b[j]=0;
			j=i;
			b[i]=1;
		}
	}
	m--;
	f4(x,m);
	b[j]=0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		b[i]=1;
		ans=max(ans,f4(a[i],m-1));
		b[i]=0;
	}
	cout<<ans;
	return 0;
}
