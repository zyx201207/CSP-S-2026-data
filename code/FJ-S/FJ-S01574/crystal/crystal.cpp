#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500001], l, r, cha;
long long read() {
	long long f=1, cnt=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') f*=-1, ch=getchar();
	while(ch<='9'&&ch>='0') cnt=cnt*10+ch-'0', ch=getchar();
	return f*cnt;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out","w",stdout);
	n=read(), m=read(), l=1, r=m/2;
	for(int i=1; i<=n; i++) a[i]=read();
	sort(a+1, a+n+1);
	cha=a[2]-a[1];
	while(l<=r) {
		long long mid=(l+r)/2;
		if(mid()*(mid+1)==2*m||((mid+1)*(mid+2)>m*2&&mid*(mid+1)<2*m)) break;
		if(mid*(mid+1)<2*m) l=mid;
		else r=mid;
	}
	cout<<((l+r)/2+1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
