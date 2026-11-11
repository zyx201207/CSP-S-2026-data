#include <bits/stdc++.h>
using namespace std;
//warning：提交的时候一定要删除注释！一定要把给定的文件名写上去！
long long a[500005],f[500005];
long long m,n;
long long read() {
	long long f=1,k=0;
	char c;
	c=getchar();
	while (c<'0'||c>'9') {
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9') {
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	long long top=1,now=1,ans=1,k=0;
	for (;now<=n;now++) {
		k=k+(now-top)*(a[now]-a[now-1]);
		while (k>m) {
			k-=(a[now]-a[top]);
			top++;
		}
		ans=max(ans,now-top+1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}