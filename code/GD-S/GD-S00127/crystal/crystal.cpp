#include<bits/stdc++.h>
using namespace std;
#define int long long
using pii=pair<int,int>;
#define fi first
#define se second
inline int read(){
	int t=1,c=getchar(),res=0;
	for(;!isdigit(c);c=getchar())if(c=='-')t=-t;
	for(;isdigit(c);c=getchar())res=(res<<1)+(res<<3),res+=c^48;
	return res*t;
}
inline void write(int num){
	if(num<0)putchar('-'),num=-num;
	if(num>9)write(num/10);
	putchar('0'+num%10);
	return;
}
const int N=5e5;
int a[N+7],s[N+7];
int n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	int ans=1;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		int l=0,r=i-1;
		while(l<=r){
			int mid=l+r>>1;
			if(s[i]-s[mid]+m>=a[i]*(i-mid))r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-l);
	}
	write(ans),putchar('\n');
	return 0;
}
