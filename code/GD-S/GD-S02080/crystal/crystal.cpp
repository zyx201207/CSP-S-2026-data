#include<bits/stdc++.h>

#define ll long long
#define int ll

using namespace std;

int read() {
	int x=0,f=1; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x*10)+(ch-'0');
	return x*f;
}

const int maxn = 500050;

int n,m;
int a[maxn];
int sum[maxn];

signed main() {
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	n=read(); m=read();
//	cout<<m<<'\n';
	for(int i=1;i<=n;i++) a[i]=read(); 
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=1;//if u r the 1st,u can get a point whatever you do 
	for(int i=2;i<=n;i++) {
		if(a[i]-a[i-1]>m) continue ;
		int l=1,r=i;
		while(l<r) {
			int mid=l+r>>1;
			if(a[i]*(i-mid)-(sum[i-1]-sum[mid-1])<=m) r=mid;
			else l=mid+1; 
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<'\n';
	return 0;
}


/*
bu hui shi san ge tu lun ba
bie xia wo
*/
