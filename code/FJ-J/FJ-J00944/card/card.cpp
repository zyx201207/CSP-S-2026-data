#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();
	int x=0,f=1;
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
	return;
}
int n,m,a[10005],b[10005],cnt,c[10005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int point=0;
			for(int k=1;k<=cnt;k++){
				if(b[k]==a[j]){
					point=k;
					break;
				}
			}
			if(!point) b[++cnt]=a[j];
			else{
				cnt=point-1;
				b[++cnt]=a[j];
			}
		}
//		for(int j=1;j<=cnt;j++){
//			write(b[j]);
//			printf(" ");
//		}
//		printf("\n");
		for(int j=1;j<=cnt;j++){
			c[b[j]]++;
		}
		cnt=0;
	}
	for(int i=1;i<=m;i++){
		write(c[i]);
		printf(" ");
	}
	return 0;
}
