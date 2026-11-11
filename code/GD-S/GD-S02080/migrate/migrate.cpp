#include<bits/stdc++.h>

#define ll long long
#define int ll
#define pii pair<int,int>

using namespace std;

int read() {
	int x=0,f=1; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x*10)+(ch-'0');
	return x*f;
}

const int maxn = 1000600;

int n,d;
int a[maxn];

int f[maxn],g[maxn];
int cnt[maxn];

int calc(int idx) {
	for(int i=0;i<=n;i++) f[i]=1e18,g[i]=0,cnt[i]=0;
	f[idx]=0,g[idx]=1; 
	cnt[0]=1; int k=0,lst=idx; int ans=0;
	for(int i=idx+1;i<=n;i++) {
		while(a[i]-a[lst]>d&&lst<i) {
			cnt[f[lst]]-=g[lst]; lst++;
		}
		if(lst==i) break ;
		while(cnt[k]==0&&k<=n) k++;
		f[i]=f[lst]+1,g[i]=cnt[f[lst]]; cnt[f[i]]+=g[i];
		if(g[i]==2) ans++;
		if(k==n+1) break ;
	}
	return ans;
}

void work() {
	n=read(),d=read();
	for(int i=1;i<=n;i++) a[i]=read();
	int ans=0;
	for(int i=1;i<=n;i++) {
		ans+=calc(i);
	}
	cout<<ans<<'\n';
}

void spwork() {
	n=read(),d=read();
	for(int i=1;i<=n;i++) a[i]=read();
	if(n==1) {
		cout<<0<<'\n'; return ;
	}
//	cout<<n<<' '<<d<<' '<<a[2]-a[1]<<' '<<d/(a[2]-a[1])<<'\n';
	int del=d/(a[2]-a[1]);
	if(del<=1) {
		cout<<0<<'\n';
	} else {
		cout<<max(0ll,n-(del+del-1))<<'\n';
	}
}

signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	int c=read(),_=read();
	
	if(c>=11&&c<=12) {
		while(_--) 	{
			spwork();
		}
		return 0;
	}
	
	while(_--) {
		work();
	}
	return 0;
}


/*
zhe ge yang li qiang du hui bu hui tai gao le a
yi ji zhe ge t zen me you ke neng an xia qubu fan tan a
zheng jian?!awmc mei jiu le 
*/

/*
si,si lu you dian jia

40 pts pao lu le
wo yao wan mo fa shi
wo yao da feng yan
wo yao da wu meng
*/
