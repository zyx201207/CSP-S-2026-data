#include<bits/stdc++.h>
#define int long long
using namespace std;
char buf[1<<20],*p1,*p2;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin)),p1==p2?EOF:*p1++)
inline int read(){
	int k=0,f=1;char c=gc();
	for(;!isdigit(c);c=gc()) if(c=='-') f=-1;
	for(;isdigit(c);c=gc()) k=k*10+(c^48);
	return k*f; 
}
const int N=5e5+5;
int n,m,a[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
//	auto t0=clock();
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	int sum=0,cnt=1;
	ans=1;
	for(int i=2,j=1;i<=n;i++){
		sum+=(a[i]-a[i-1])*cnt;
		cnt++;
		while(j<i&&sum>m) j++,cnt--,sum-=a[i]-a[j];
//		cout<<j<<' '<<i<<' '<<cnt<<' '<<sum<<'\n';
		ans=max(ans,i-j+1);
	}
	cout<<ans;
//	cerr<<clock()-t0;
	return 0;
}
