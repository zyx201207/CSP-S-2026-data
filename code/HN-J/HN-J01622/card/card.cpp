#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005],b[300005],c[500005],e[300005],num;
struct data{
	long long l,r;
}d[500005];
void solve(long long x){
	long long k=0,p=0;
	for(long long i=1;i<=num;i++){
		if(d[i].l>k || d[i].l<p && d[i].l>=x){
			k=d[i].r;p=d[i].l;
			for(long long j=p;j<=k;j++)c[i]=0;
		}
	}
	for(long long i=1;i<=n;i++)if(a[i])e[a[i]]++;
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	for(long long i=1;i<=n;i++){
		if(b[a[i]]){
			d[++num].l=b[a[i]];
			b[a[i]]=i;
			d[num].r=i-1;
		}else b[a[i]]=i;
	}
	for(long long i=1;i<=n;i++){
		solve(i);
	}
	for(long long i=1;i<=m;i++)cout<<e[i]<<' ';
	
	return 0;
}
