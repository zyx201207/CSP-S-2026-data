#include<bits/stdc++.h>
using namespace std;
const long long N=5*1e6+5;
long long n,m,a[N],qzh[N],ans;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x*f;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		qzh[i]=qzh[i-1]+a[i];
	}
	for(long long i=1,j=1;i<=n;i++){
		while(j<=i&&a[i]*(i-j+1)-(qzh[i]-qzh[j-1])>m)j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans<<endl;
	return 0;
}
