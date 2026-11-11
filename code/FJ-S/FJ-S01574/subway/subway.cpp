#include<bits/stdc++.h>
#define N int(5e5+1)
using namespace std;
priority_queue< vector<int> ,vector<int>, greater<int> >q;
int a[N], head[2*N], last[2*N], to[2*N], w[2*N], cnt, k,;
int read() {
	int f=1, cnt=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') f*=-1, ch=getchar();
	while(ch<='9'&&ch>='0') cnt=cnt*10+ch-'0', ch=getchar();
	return f*cnt;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out","w",stdout);
	c=read(), n=read(), m=read(), d=read(), q=read();
	for(int i=1; i<=m; i++) a[i]=read();
	for(int i=1; i<=n; i++) {
		k=read();
		for(int j=1; j<=n; j++) 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
