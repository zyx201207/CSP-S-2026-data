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
const int N=5e5+5;
int n, m, a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	a[0]=a[1];
	int ma=0, sum=0;
	for(int l=1, r=1;r<=n;r++){
		sum+=(r-l)*(a[r]-a[r-1]);
		while(sum>m){
			sum-=(a[r]-a[l]);
			l++;
		}
		ma=max(ma,r-l+1);
	}
	write(ma);
	return 0;
}
