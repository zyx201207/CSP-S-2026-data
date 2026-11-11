#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+5;
int n, m, a[maxn], sum, tot, ans, q[maxn];
inline int read(){
	int x=0, f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int ef(int i){
	int L=1, R=i, mid=0, re=i;
	while(L<=R){
		mid=(L+R)>>1;
		if((i-mid+1)*a[i]-(q[i]-q[mid-1])<=m){
			R=mid-1;
			re=mid;
		}else{
			L=mid+1;
		}
	}
	return re;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		q[i]=q[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,i-ef(i)+1);
	}
	write(ans);
	return 0;
}
/*
T:O(nlogn)
M:
*/

