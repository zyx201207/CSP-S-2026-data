#include<bits/stdc++.h>
#define ll long long
#define enter putchar('\n');
#define space putchar(' ');
using namespace std;
const int N=5e5+5;
ll read();
void write(ll x);
ll n,m,a[N],d[N];
int ans;
bool check(int l,int r){
	if(a[r]*(r-l+1)-d[r]+d[l-1]<=m) return true;
	else return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) d[i]=d[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(check(mid,i)) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	write(ans);
	return 0;
}
/*
5 5
1 2 4 8 9
*/
ll read(){
	ll op=1,cnt=0;
	int c;
	c=getchar();
	while(c<'0'||'9'<c){
		if(c=='-') op*=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		cnt=cnt*10+c-'0';
		c=getchar();
	}
	return op*cnt;
}
void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
