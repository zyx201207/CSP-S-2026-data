#include<bits/stdc++.h>
#define int long long
using namespace std;
const int dd=5e5+5;
int n,m;
int a[dd];
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
void write(int x)
{
	if(x<0){
		putchar('-');
		write(-x);
		return;
	}
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
bool check(int x)
{
	int sum=0;
	for(int i=1;i<x;i++) sum+=(a[x]-a[i]);
	if(sum<=m) return 1;
	for(int i=x+1;i<=n;i++){
		sum-=(a[i-1]-a[i-x]);
		sum+=(x-1)*(a[i]-a[i-1]);
		if(sum<=m) return 1;
	}
	return sum<=m;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
