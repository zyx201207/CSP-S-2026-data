#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,maxx=-1;
long long a[500005],b[500005];
long long fen30(){
	for(long long i=n-1;i>=1;i--){
		if(m-abs(a[n]-a[i])>=0){
			m=m-abs(a[n]-a[i]);
			sum++;
		}
		else break;
	}
	return sum;
}
int fen20(int s,int m1){
	sum=0;
	if(s==0){
		return maxx;
	}
	for(int i=s;i>=1;i--){
		if(m1-(a[s]-a[i])>=0){
			m1=m1-(a[s]-a[i]);
			sum++;
		}
		else break;
	}
	sum++;
	maxx=max(sum,maxx);
	if(m1!=0){
		fen20(s-1,m);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(m==0){
		for(int i=1;i<=n;i++){
			b[a[i]]++;
		}
		for(int i=1;i<=n;i++){
			maxx=max(maxx,b[a[i]]);
		}
		printf("%lld",maxx);
		return 0;
	}
	if(n>=500000){
		fen30();
		sum++;
		printf("%lld",sum);
		return 0;
	}
	if(n<=5000&&m!=0){
		sort(a+1,a+n+1);
		int ss=fen20(n,m);
		ss--;
		printf("%d",ss);
		return 0;
	}
	return 0;
}
