#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48),ch=getchar();}
	return x*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+48);
}
const int maxn=5e5+5;
int n,m,a[maxn],sum[maxn];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	// 选定 a[R] 为目标值，那么二分找到最远可达的位置 L
	// a[R]-a[L]+a[R]-a[L+1]+...+a[R]-a[R-1] <= m
	// 即 a[R]*(R-L) - (a[L]+...+a[R-1]) <= m 
	// a[L]+...+a[R-1] >= a[R]*(R-L)-m，候选答案就是 R-L+1
	int ans=1;
	for(int R=1;R<=n;R++){
		sum[R]=sum[R-1]+a[R];
		int l=1,r=R-1,L=R;
		while(l<=r){
			int mid=(l+r)>>1;
			if(sum[R-1]-sum[mid-1]>=a[R]*(R-mid)-m)r=mid-1,L=mid;
			else l=mid+1;
		}
		ans=max(ans,R-L+1);
	}
	write(ans);
	return 0;
}
