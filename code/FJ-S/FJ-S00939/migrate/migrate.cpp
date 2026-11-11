#include<bits/stdc++.h>
using namespace std;
const long long N=5*1e6+5,inf=1e18;
long long c,tt,n,d,a[N],ans;
long long h,t;
struct hhh{
	long long len,k;
}b[N];
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x*f;
}
void solve(){
	n=read();d=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	if(c==11||c==12){
		if(n==1)cout<<0<<endl;
		else cout<<n-(d/(a[2]-a[1]))<<endl;
	}
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[j].k=0;b[j].len=inf;
		}
		b[i].k=1;b[i].len=0;
		for(int r=i+1,l=i;r<=n;r++){
			while(l<=r&&a[r]-a[l]>d)l++;
			if(l==r)break;
			b[r].len=b[l].len+1;
			b[r].k=b[l].k;
			for(int j=l+1;b[r].k<=2&&j<=r;j++){
				if(b[j].len!=b[j-1].len)break;
				b[r].k+=b[j].k;
			}
			if(b[r].k==2){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();tt=read();
	while(tt--){
		solve();
	}
	return 0;
}
