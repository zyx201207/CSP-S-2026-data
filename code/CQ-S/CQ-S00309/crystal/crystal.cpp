#include<bits/stdc++.h>
#define int long long
#define endl putchar('\n')
#define psp putchar(' ')
using namespace std;
const int N=5e5+5;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x<10){
		putchar(x+'0');
		return;
	}
	print(x/10);
	putchar(x%10+'0');
}
int n,m,k;
int T;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int sum[N];
int ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(l<r){
			int mid=l+1+r>>1;
			if(a[i]*(mid-i+1)-(sum[mid]-sum[i-1])<=m)l=mid;
			else r=mid-1;
		}
		ans=max(ans,l-i+1);
	}
	print(ans);
}

