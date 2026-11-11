#include <bits/stdc++.h>
using namespace std;
long long read(){
	long long x=0;
	char c=getchar();
	while(c<'0'||'9'<c) c=getchar();
	while('0'<=c&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
void write(long long x){
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
int n,m,a[500010],b[500010],l=1;
long long sum[500010];
int f[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		l=1;
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++){
			if(f[a[j]]!=0){
				for(int k=f[a[j]]+1;k<l;k++) f[b[k]]=0;
				l=f[a[j]];
			}
			else{
				f[a[j]]=l;
				b[l]=a[j];
			}
			l++;
		}
		for(int j=1;j<l;j++) sum[b[j]]++;
	}
	for(int i=1;i<=m;i++){
		write(sum[i]);
		putchar(' ');
	}
	return 0;
}
