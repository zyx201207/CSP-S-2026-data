#include<bits/stdc++.h>
using namespace std;
long long maxn=-1e18-10;
long long n,m;
long long a[500005]={};
long long b[500005]={};
int check(int x){
	
	long long y=m,cnt=0;
	for(int i=n;i>=1;i--){
		b[i]=a[i];
		if(a[i]<x&&y-(x-a[i])>=0){
			y-=x-a[i];
			b[i]=x;
		}
		if(b[i]==x)cnt++;
	}
	
	return cnt;
}
void f(long long l,long long r){
	if(l<=r){
		int mid=l+(r-l+1)/2;
		long long j=check(mid);
		maxn=max(maxn,j);
		long long it=lower_bound(a+1,a+1+n,mid)-a;
		
		if(j<it-1){
			return f(l,mid-1);
		}else{
			return f(mid+1,r);
		}
		
		
			
		
	}		
}
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	
	
	for(int i=1;i<=n;i++){
		a[i]=read();
	}sort(a+1,a+1+n);
	long long l=1,r=m;
	f(l,r);
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

