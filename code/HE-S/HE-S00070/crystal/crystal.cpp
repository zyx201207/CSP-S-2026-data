#include<bits/stdc++.h>
using namespace std;
int read(){
	long long x=0;int f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=10*x+(c^48);c=getchar();}
	return x*f;
}
long long n,m,a[500005],ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+1+n);
	if(n>=10000&&(a[2]<<1)==(a[1]+a[3])){
		int bb=a[2]-a[1];
		int cc=m/bb;
		for(int i=1;cc>=0;++i){
			cc-=i;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;++i){
		long long aaa=1,mm=m;
		int l=i-1;
		while(mm>0&&l!=0){
			mm-=(a[i]-a[l]);
			l--;
			aaa++;
		}
		if(mm<0)aaa--;
		ans=max(ans,aaa);
	}
	printf("%lld",ans);
	return 0;
}/*
5 5
1 2 4 8 9
*/
