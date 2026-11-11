#include<bits/stdc++.h>
using namespace std;
const long long N=1e5*5+1;
int sum=1;
long long n,m;
int mi=1;
int sy=0;
long long a[N];/*find the smallest shuijing*/
/*
 24min,new idea
 */
/*auto*/long long read(){
	char c=getchar_unlocked();
	/*auto*/long long sum=0;
	int f=1;
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar_unlocked();
	}
	while(c>='0'&&c<='9'){
		sum*=10;
		sum+=c-'0';
		c=getchar_unlocked();
	}
	return sum*f;
}
void write(/*auto*/long long sum){
	int s=-1;
	char c[20];
	if(sum<0){
		sum=-sum;
		putchar_unlocked('-');
	}
	if(sum==0){
		putchar_unlocked('0');
		return ;
	}
	while(sum!=0){
		c[++s]=sum%10+'0';
		sum/=10;
	}
	for(int i=s;i>=0;i--) putchar_unlocked(c[i]);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		sy+=(i-mi)*(a[i]-a[i-1]);
		if(sy<=m)
			sum=max(sum,i-mi+1);
		else{
			for(int j=mi;j<=i-1;j++){
				sy-=a[i]-a[mi];
				mi++;
				if(sy<=m) break;
			}
			sum=max(sum,i-mi+1);
		}
	}
	write(sum);
	return 0;
}
