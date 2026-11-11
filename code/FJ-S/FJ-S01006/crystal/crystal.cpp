#include<bits/stdc++.h>
using namespace std;
long long n,m,s,ans,cnt,a[1000005];
long long read(){
	long long ans=0;
	char c=0;
	bool f=0;
	while(c<'0'||c>'9')c=getchar(),f|=(c=='-');
	while(c>='0'&&c<='9')ans=ans*10+c-'0',c=getchar();
	return f?-ans:ans;
}
void write(long long x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1),cnt=1;
	for(int i=1;i<=n;i++){
		s+=(i-cnt)*(a[i]-a[i-1]);
		while(cnt<=i&&s>m)s-=a[i]-a[cnt],cnt++;
		ans=max(ans,i-cnt+1);
	}
	write(ans);
	return 0;
}
