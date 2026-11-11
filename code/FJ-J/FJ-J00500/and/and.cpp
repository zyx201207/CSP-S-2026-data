#include <bits/stdc++.h>
#define int long long
#define endl putchar('\n')
#define lowbit(x) ((x)&(-(x)))
using namespace std;
int read(){
	char c=getchar();
	int x=0;bool flag=false;
	while(c>'9' || c<'0'){
		if(c=='-') flag=true;
		c=getchar();
	}
	while(c<='9' && c>='0'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return flag ? -x : x;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int N=2e5+5;
int a[N], pre[N], suf[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n=read(), m=read();
	bool flag=true;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(lowbit((a[i]+1))!=(a[i]+1)) flag=false;
	}
	if(n<=20){
		int ma=0;
		for(int i=1;i<(1<<n);i++){
			int sum=-1, cnt=0;
			for(int j=1;j<=n;j++){
				if(i&(1<<(j-1))){
					cnt++;
					if(sum==-1) sum=a[j];
					else sum&=a[j];
				}
			}
			if(cnt==m) ma=max(ma,sum);
		}
		write(ma);
		return 0;
	}
	if(m==1){
		int ma=0;
		for(int i=1;i<=n;i++) ma=max(ma,a[i]);
		write(ma);
		return 0;
	}
	if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++) sum&=a[i];
		write(sum);
		return 0;
	}
	if(m==2){
		int ma=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,a[i]&a[j]);
			}
		}
		write(ma);
		return 0;
	}
	if(lowbit(n)==n){
		write(n-1);
		return 0;
	}
	if(flag){
		sort(a+1,a+1+n,[](int x, int y){return x>y;});
		write(a[m]);
	}
	if(m==n-1){
		pre[1]=a[1];
		for(int i=2;i<=n;i++) pre[i]=pre[i-1]&a[i];
		suf[n]=a[n];
		for(int i=n-1;i>=1;i--) suf[i]=suf[i+1]&a[i];
		int ma=max(pre[n-1],suf[2]);
		for(int i=2;i<n;i++){
			ma=max(ma,pre[i-1]&suf[i+1]);
		}
		write(ma);
		return 0;
	}
	return 0;
}
