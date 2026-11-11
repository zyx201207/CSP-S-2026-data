#include<bits/stdc++.h>
#define int long long 
#define LOCAL 0
#define ONLINE 1
using namespace std;
const int N=2e6+10;
int T,C;
namespace sl1{
	int n,d,x[N],tag[N],ans,p,l,r;
	void solve(){
		ans=0;
		l=r=0;//双径区间 //p-l单径
		p=1;
		//r-i单径 
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
//		for(int i=1;i<=n;i++)cout<<x[i]<<' ';cout<<'\n';
//		cout<<n<<' '<<d<<'\n';
		for(int i=1,j=1,p1=1,p2=1;i<=n;i++){
			while(p1<i&&x[i]-x[p1]>d)p1++;
			while(j<p1&&x[p1]-x[j]>d)j++;
			while(p2<i&&x[i]-x[p2]>d)p2++;
			while(p2<i&&x[p2+1]-x[j]<=d)p2++;
			if(j<p1&&p1+1==p2&&p2<i)l=j,r=i;
			if(j<p1&&p1+1<p2&&p2<i)l=r=0,p=j+1;
			if(i==j)l=r=0,p=j; 
		//	cout<<j<<' '<<p1<<' '<<p2<<' '<<i<<'|'<<p<<' '<<l<<' '<<r<<' '<<i<<'\n';
			if(l==0&&r==0)continue;
			ans+=(l-p+1);
		}
		
		cout<<ans<<'\n';
	}
}
/*
双径序列只有一个不同
set mx_p 

*/
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#if LOCAL 
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	#if ONLINE 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	#endif
	cin>>C>>T;
	while(T--)sl1::solve();
}
