#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
inline ll readl(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
inline void print(ll x){
	stack<char> s;
	do{
		s.push(x%10+'0');
		x/=10;	
	}while(x);
	while(!s.empty()){
		putchar(s.top());		
		s.pop();	
	}
}
const int N=5e5+10;
ll a[N];
ll c[N];
ll sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=read();
	ll m=readl();
	for(int i=1;i<=n;++i)a[i]=readl();
	sort(a+1,a+n+1);
	if(a[1]<0){
		for(int i=2;i<=n;++i)a[i]+=-a[1];
		a[1]=0;
	}
	for(int i=1;i<n;++i)c[i]=a[i+1]-a[i];
	for(int i=1;i<n;++i)sum[i]=sum[i-1]+c[i];
	a[0]=0;
	for(int i=1;i<n;++i)a[i]=i*c[i]-sum[i-1];
	print(upper_bound(a+1,a+n+1,m)-a);
	return 0;
}
